#include <Rcpp.h>
#include <RcppThread.h>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include "types.h"
#include "utils-internal.h"

std::unordered_map<std::string, int> METRICS_enum = {

  /* distance */

  {"EUCL",   1},
  {"MEUCL",  2},
  {"KL",     3},
  {"MKL",    4},

  /* similarity */

  {"PCC",    5},
  {"MPCC",   6},
  {"SW",     7},
  {"MSW",    8},
  {"ALLR",   9},
  {"MALLR", 10}

};

double compare_eucl(const list_num_t &mot1, const list_num_t &mot2,
    const bool norm = false) {

  std::size_t ncol = mot1.size(), nrow = mot1[0].size();
  list_num_t diffmat(ncol, vec_num_t(nrow, 0.0));
  vec_bool_t good(ncol, false);
  for (std::size_t i = 0; i < ncol; ++i) {
    if (mot1[i][0] >= 0 && mot2[i][0] >= 0) good[i] = true;
  }

  for (std::size_t i = 0; i < ncol; ++i) {

    if (good[i]) {

      for (std::size_t j = 0; j < nrow; ++j) {
        diffmat[i][j] = mot1[i][j] - mot2[i][j];
        diffmat[i][j] = pow(diffmat[i][j], 2.0);
      }

    }

  }

  vec_num_t colsums(ncol, 0.0);
  for (std::size_t i = 0; i < ncol; ++i) {
    if (good[i]) {
      for (std::size_t j = 0; j < nrow; ++j) {
        colsums[i] += diffmat[i][j];
      }
      colsums[i] = sqrt(colsums[i]);
    }
  }

  double k = 0.0;
  int counter = 0;
  for (std::size_t i = 0; i < ncol; ++i) {
    if (good[i]) {
      ++counter;
      k += colsums[i];
    }
  }

  return norm ? k / double(counter) / sqrt(2.0) : k / sqrt(2.0);

}

double compare_pcc(const list_num_t &mot1, const list_num_t &mot2,
    const bool norm = false) {

  std::size_t ncol = mot1.size(), nrow = mot1[0].size();
  vec_bool_t good(ncol, false);
  int n = 0;
  for (std::size_t i = 0; i < ncol; ++i) {
    if (mot1[i][0] >= 0 && mot2[i][0] >= 0) {
      good[i] = true;
      ++n;
    }
  }

  list_num_t mmat(ncol, vec_num_t(nrow, 0.0));
  for (std::size_t i = 0; i < ncol; ++i) {
    if (good[i]) {
      for (std::size_t j = 0; j < nrow; ++j) {
        mmat[i][j] = mot1[i][j] * mot2[i][j];
      }
    }
  }

  list_num_t pmat1(ncol, vec_num_t(nrow, 0.0));
  list_num_t pmat2(ncol, vec_num_t(nrow, 0.0));
  for (std::size_t i = 0; i < ncol; ++i) {
    if (good[i]) {
      for (std::size_t j = 0; j < nrow; ++j) {
        pmat1[i][j] = pow(mot1[i][j], 2.0);
        pmat2[i][j] = pow(mot2[i][j], 2.0);
      }
    }
  }

  vec_num_t top(ncol);
  for (std::size_t i = 0; i < ncol; ++i) {
    if (good[i]) {
      top[i] = double(nrow) * std::accumulate(mmat[i].begin(), mmat[i].end(), 0.0);
      top[i] -= std::accumulate(mot1[i].begin(), mot1[i].end(), 0.0)
                * std::accumulate(mot2[i].begin(), mot2[i].end(), 0.0);
    }
  }

  vec_num_t bot(ncol);
  for (std::size_t i = 0; i < ncol; ++i) {
    if (good[i]) {
      bot[i] = double(nrow) * std::accumulate(pmat1[i].begin(), pmat1[i].end(), 0.0)
               - pow(std::accumulate(mot1[i].begin(), mot1[i].end(), 0.0), 2.0);
      bot[i] *= double(nrow) * std::accumulate(pmat2[i].begin(), pmat2[i].end(), 0.0)
                - pow(std::accumulate(mot2[i].begin(), mot2[i].end(), 0.0), 2.0);
      bot[i] = sqrt(bot[i]);
    }
  }

  vec_num_t topbot(ncol, 0.0);
  for (std::size_t i = 0; i < ncol; ++i) {
    if (good[i]) {
      topbot[i] = bot[i] == 0 ? 0.0 : top[i] / bot[i];
      // topbot[i] = top[i] / bot[i];  // --> get Inf values if both mot1[i] and mot2[i]
    }                                  //     are uniform (e.g. {0.25, 0.25, 0.25, 0.25})
  }

  double total = std::accumulate(topbot.begin(), topbot.end(), 0.0);

  return norm ? total / double(n) : total;

}

double compare_kl(const list_num_t &mot1, const list_num_t &mot2,
    const bool norm = false) {

  std::size_t ncol = mot1.size(), nrow = mot1[0].size();
  vec_bool_t good(ncol, false);
  for (std::size_t i = 0; i < ncol; ++i) {
    if (mot1[i][0] >= 0 && mot2[i][0] >= 0) good[i] = true;
  }

  list_num_t nmat(ncol, vec_num_t(nrow, 0.0));
  for (std::size_t i = 0; i < ncol; ++i) {
    if (good[i]) {
      for (std::size_t j = 0; j < nrow; ++j) {
        nmat[i][j] = mot1[i][j] * log(mot1[i][j] / mot2[i][j]);
        nmat[i][j] += mot2[i][j] * log(mot2[i][j] / mot1[i][j]);
      }
    }
  }

  vec_num_t colsums(ncol, 0.0);
  int counter = 0;
  for (std::size_t i = 0; i < ncol; ++i) {
    if (good[i]) {
      for (std::size_t j = 0; j < nrow; ++j) {
        colsums[i] += nmat[i][j];
      }
      ++counter;
    }
  }

  double total = 0.0;
  for (std::size_t i = 0; i < ncol; ++i) {
    if (good[i]) {
      total += colsums[i];
    }
  }

  return norm ? 0.5 / double(counter) * total : 0.5 * total;

}

double compare_allr(const list_num_t &mot1, const list_num_t &mot2,
    const vec_num_t &bkg1, const vec_num_t &bkg2, const double nsites1,
    const double nsites2, const bool norm = false) {

  std::size_t ncol = mot1.size(), nrow = mot1[0].size();
  vec_bool_t good(ncol, false);
  int counter = 0;
  for (std::size_t i = 0; i < ncol; ++i) {
    if (mot1[i][0] >= 0 && mot2[i][0] >= 0) {
      good[i] = true;
      ++counter;
    }
  }

  list_num_t left(ncol, vec_num_t(nrow, 0.0)), right(ncol, vec_num_t(nrow, 0.0));
  for (std::size_t i = 0; i < ncol; ++i) {
    if (good[i]) {
      for (std::size_t j = 0; j < nrow; ++j) {
        left[i][j] = (mot2[i][j] * nsites2) * log(mot1[i][j] / bkg1[j]);
        right[i][j] = (mot1[i][j] * nsites1) * log(mot2[i][j] / bkg2[j]);
      }
    }
  }

  vec_num_t answers(ncol, 0.0);
  for (std::size_t i = 0; i < ncol; ++i) {
    if (good[i]) {
      answers[i] = std::accumulate(left[i].begin(), left[i].end(), 0.0);
      answers[i] += std::accumulate(right[i].begin(), right[i].end(), 0.0);
      answers[i] /= nsites1 + nsites2;
    }
  }

  double total = std::accumulate(answers.begin(), answers.end(), 0.0);

  return norm ? total / double(counter) : total;

}

double compare_sw(const list_num_t &mot1, const list_num_t &mot2,
    const bool norm = false) {

  std::size_t ncol = mot1.size(), nrow = mot1[0].size();
  vec_bool_t good(ncol, false);
  for (std::size_t i = 0; i < ncol; ++i) {
    if (mot1[i][0] >= 0 && mot2[i][0] >= 0) good[i] = true;
  }

  list_num_t nmat(ncol, vec_num_t(nrow, 0.0));
  for (std::size_t i = 0; i < ncol; ++i) {
    if (good[i]) {
      for (std::size_t j = 0; j < nrow; ++j) {
        nmat[i][j] = pow(mot1[i][j] - mot2[i][j], 2.0);
      }
    }
  }

  vec_num_t colsums(ncol, 2.0);
  double total = 0.0;
  int counter = 0;
  for (std::size_t i = 0; i < ncol; ++i) {
    if (good[i]) {
      for (std::size_t j = 0; j < nrow; ++j) {
        colsums[i] -= nmat[i][j];
      }
      total += colsums[i];
      ++counter;
    }
  }

  return norm ? total / double(counter) : total;

}

void klfix(list_num_t &mot) {
  for (std::size_t i = 0; i < mot.size(); ++i) {
    for (std::size_t j = 0; j < mot[0].size(); ++j) {
      mot[i][j] += 0.01;
    }
  }
  return;
}

void bkgfix(vec_num_t &bkg) {
  bool fix = false;
  for (std::size_t i = 0; i < bkg.size(); ++i) {
    if (bkg[i] == 0) {
      fix = true;
      break;
    }
  }
  if (fix) {
    for (std::size_t i = 0; i < bkg.size(); ++i) {
      bkg[i] += 0.01 * (1.0 / double(bkg.size()));
    }
  }
  return;
}

void equalize_mot_cols(list_num_t &mot1, list_num_t &mot2,
    vec_num_t &ic1, vec_num_t &ic2, const int overlap) {

  std::size_t nrow = mot1[0].size();
  std::size_t ncol1 = mot1.size();
  std::size_t ncol2 = mot2.size();
  std::size_t overlap1 = overlap, overlap2 = overlap;

  if (overlap < 1) {
    overlap1 *= ncol1;
    overlap2 *= ncol2;
  }

  std::size_t ncol1_toadd = overlap1 > ncol2 ? 0 : ncol2 - overlap1;
  std::size_t ncol2_toadd = overlap2 > ncol1 ? 0 : ncol1 - overlap2;

  if (ncol1_toadd == 0 || ncol2_toadd == 0) return;

  if (ncol2 > ncol1) {

    list_num_t newmot(ncol1_toadd * 2 + ncol1, vec_num_t(nrow, -1.0));
    vec_num_t newic(ncol1_toadd * 2 + ncol1, 0.0);

    for (std::size_t i = ncol1_toadd; i < ncol1_toadd + ncol1; ++i) {
      newmot[i].assign(mot1[i - ncol1_toadd].begin(), mot1[i - ncol1_toadd].end());
    }

    for (std::size_t i = ncol1_toadd; i < ncol1_toadd + ncol1; ++i) {
      newic[i] = ic1[i - ncol1_toadd];
    }

    mot1.assign(newmot.begin(), newmot.end());
    ic1.assign(newic.begin(), newic.end());

  } else {

    list_num_t newmot(ncol2_toadd * 2 + ncol2, vec_num_t(nrow, -1.0));
    vec_num_t newic(ncol2_toadd * 2 + ncol2, 0.0);

    for (std::size_t i = ncol2_toadd; i < ncol2_toadd + ncol2; ++i) {
      newmot[i].assign(mot2[i - ncol2_toadd].begin(), mot2[i - ncol2_toadd].end());
    }

    for (std::size_t i = ncol2_toadd; i < ncol2_toadd + ncol2; ++i) {
      newic[i] = ic2[i - ncol2_toadd];
    }

    mot2.assign(newmot.begin(), newmot.end());
    ic2.assign(newic.begin(), newic.end());

  }

  return;

}

int get_alignlen(const list_num_t &mot1, const list_num_t &mot2) {

  int out = 0;
  for (std::size_t i = 0; i < mot1.size(); ++i) {
    if (mot1[i][0] >= 0 && mot2[i][0] >= 0) ++out;
  }

  return out;

}

double calc_mic(const vec_num_t &tic) {

  double out = 0.0;
  int counter = 0;

  for (std::size_t i = 0; i < tic.size(); ++i) {
    if (tic[i] >= 0) {
      out += tic[i];
      ++counter;
    }
  }

  return out / double(counter);

}

list_num_t get_motif_rc(const list_num_t &mot) {

  list_num_t rcmot = mot;
  std::reverse(rcmot.begin(), rcmot.end());
  for (std::size_t i = 0; i < rcmot.size(); ++i) {
    std::reverse(rcmot[i].begin(), rcmot[i].end());
  }

  return rcmot;

}

void fix_lowic_pos(list_num_t &tmot1, list_num_t &tmot2,
    vec_num_t &tic1, vec_num_t &tic2, const double posic) {

  for (std::size_t i = 0; i < tmot1.size(); ++i) {
    if (tic1[i] < posic) {
      for (std::size_t j = 0; j < tmot1[0].size(); ++j) {
        tmot1[i][j] = -1.0;
      }
      tic1[i] = -1.0;
    }
    if (tic2[i] < posic) {
      for (std::size_t j = 0; j < tmot1[0].size(); ++j) {
        tmot2[i][j] = -1.0;
      }
      tic2[i] = -1.0;
    }
  }

  return;

}

void get_compare_ans(vec_num_t &ans, const std::size_t i,
    const list_num_t &tmot1, const list_num_t &tmot2, const bool lowic,
    const bool norm, const int alignlen, const std::size_t tlen,
    const std::string &method, const double nsites1, const double nsites2,
    const vec_num_t &bkg1, const vec_num_t &bkg2) {

  switch (::METRICS_enum[method]) {

    case  1: ans[i] = lowic ? sqrt(2.0) * double(alignlen)
                              : compare_eucl(tmot1, tmot2, false)
                                * double(tlen) / double(alignlen);
             break;
    case  2: ans[i] = lowic ? sqrt(2.0)
                              : compare_eucl(tmot1, tmot2, true)
                                * double(tlen) / double(alignlen);
             break;
    case  3: ans[i] = lowic ? 5.0 * double(alignlen)
                              : compare_kl(tmot1, tmot2, false)
                                * double(tlen) / double(alignlen);
             break;
    case  4: ans[i] = lowic ? 5.0
                              : compare_kl(tmot1, tmot2, true)
                                * double(tlen) / double(alignlen);
             break;
    case  5: ans[i] = lowic ? -1.0 * double(alignlen)
                              : compare_pcc(tmot1, tmot2, false)
                                * double(alignlen) / double(tlen);
             break;
    case  6: ans[i] = lowic ? -1.0
                              : compare_pcc(tmot1, tmot2, true)
                                * double(alignlen) / double(tlen);
             break;
    case  7: ans[i] = lowic ? -2.0 * double(alignlen)
                              : compare_sw(tmot1, tmot2, false)
                                * double(alignlen) / double(tlen);
             break;
    case  8: ans[i] = lowic ? -2.0
                              : compare_sw(tmot1, tmot2, true)
                                * double(alignlen) / double(tlen);
             break;
    case  9: ans[i] = lowic ? -4.0 * double(alignlen)
                              : compare_allr(tmot1, tmot2, bkg1, bkg2, nsites1,
                                  nsites2, false)
                                * double(alignlen) / double(tlen);
             break;
    case 10: ans[i] = lowic ? -4.0
                             : compare_allr(tmot1, tmot2, bkg1, bkg2, nsites1,
                                 nsites2, true)
                               * double(alignlen) / double(tlen);
             break;

  }

  return;

}

double return_best_ans(const vec_num_t &ans, const std::string &method) {

  switch (::METRICS_enum[method]) {

    case  1: return *std::min_element(ans.begin(), ans.end());
    case  2: return *std::min_element(ans.begin(), ans.end());
    case  3: return *std::min_element(ans.begin(), ans.end());
    case  4: return *std::min_element(ans.begin(), ans.end());
    case  5: return *std::max_element(ans.begin(), ans.end());
    case  6: return *std::max_element(ans.begin(), ans.end());
    case  7: return *std::max_element(ans.begin(), ans.end());
    case  8: return *std::max_element(ans.begin(), ans.end());
    case  9: return *std::max_element(ans.begin(), ans.end());
    case 10: return *std::max_element(ans.begin(), ans.end());

  }

  return -1111.0;

}

double compare_motif_pair(list_num_t mot1, list_num_t mot2,
    const std::string method, const int moverlap, const bool RC,
    vec_num_t ic1, vec_num_t ic2, const double minic, const bool norm,
    const double posic, const vec_num_t &bkg1, const vec_num_t &bkg2,
    const double nsites1, const double nsites2) {

  double ans_rc;
  if (RC) {
    list_num_t rcmot2 = get_motif_rc(mot2);
    vec_num_t rcic2 = ic2;
    std::reverse(rcic2.begin(), rcic2.end());
    ans_rc = compare_motif_pair(mot1, rcmot2, method, moverlap, false,
        ic1, rcic2, minic, norm, posic, bkg1, bkg2, nsites1, nsites2);
  }

  std::size_t tlen = mot1.size() >= mot2.size() ? mot1.size() : mot2.size();

  equalize_mot_cols(mot1, mot2, ic1, ic2, moverlap);

  std::size_t minw = mot1.size() <= mot2.size() ? mot1.size() : mot2.size();
  list_num_t tmot1(minw), tmot2(minw);
  vec_num_t tic1(minw), tic2(minw);
  std::size_t fori = 1 + mot1.size() - minw, forj = 1 + mot2.size() - minw;
  vec_num_t ans;
  ans = RC ? vec_num_t(fori * forj + 1) : vec_num_t(fori * forj);
  int alignlen;
  double mic1, mic2;
  bool lowic = false;
  std::size_t counter = 0;

  for (std::size_t i = 0; i < fori; ++i) {
    for (std::size_t j = 0; j < forj; ++j) {

      for (std::size_t k = 0; k < minw; ++k) {
        tmot1[k] = mot1[k + i];
        tmot2[k] = mot2[k + j];
        tic1[k] = ic1[k + i];
        tic2[k] = ic2[k + j];
      }

      if (posic > 0) fix_lowic_pos(tmot1, tmot2, tic1, tic2, posic);

      alignlen = norm ? get_alignlen(tmot1, tmot2) : tlen;

      mic1 = calc_mic(tic1);
      mic2 = calc_mic(tic2);
      if (mic1 < minic || mic2 < minic) lowic = true;

      get_compare_ans(ans, counter, tmot1, tmot2, lowic, norm, alignlen, tlen,
          method, nsites1, nsites2, bkg1, bkg2);

      ++counter;
      lowic = false;

    }
  }

  if (RC) ans[counter] = ans_rc;

  return return_best_ans(ans, method);

}

double internal_posIC(vec_num_t pos, const vec_num_t &bkg,
    const int type, bool relative) {

  if (type == 2) return std::accumulate(pos.begin(), pos.end(), 0.0);

  if (relative) {
    for (std::size_t i = 0; i < pos.size(); ++i) {
      double tmp = pos[i] / bkg[i];
      pos[i] *= tmp >= 0 ? log2(tmp) : 0.0;
      if (pos[i] < 0) pos[i] = 0.0;
    }
    return std::accumulate(pos.begin(), pos.end(), 0.0);
  }

  vec_num_t heights(pos.size());
  for (std::size_t i = 0; i < pos.size(); ++i) {
    heights[i] = pos[i] > 0 ? -pos[i] * log2(pos[i]) : 0.0;
  }
  return log2(pos.size()) - std::accumulate(heights.begin(), heights.end(), 0.0);

}

list_num_t get_merged_motif(const list_num_t &mot1, const list_num_t &mot2,
    const int weight) {

  /* TODO: this is potentially dangerous with min.position.ic !!! */

  list_num_t out;
  out.reserve(mot1.size());
  for (std::size_t i = 0; i < mot1.size(); ++i) {
    if (mot1[i][0] < 0 && mot2[i][0] >= 0) {
      out.push_back(mot2[i]);
    } else if (mot2[i][0] < 0 && mot1[i][0] >= 0) {
      out.push_back(mot1[i]);
    } else if (mot1[i][0] >= 0 && mot2[i][0] >= 0) {
      vec_num_t tmp(mot1[0].size());
      for (std::size_t j = 0; j < mot1[0].size(); ++j) {
        tmp[j] = (mot1[i][j] * double(weight) + mot2[i][j]) / (double(weight) + 1);
      }
      out.push_back(tmp);
    }
  }

  return out;

}

int return_best_ans_which(const vec_num_t &ans, const std::string &method) {

  switch (::METRICS_enum[method]) {

    case  1: return std::distance(ans.begin(), std::min_element(ans.begin(), ans.end()));
    case  2: return std::distance(ans.begin(), std::min_element(ans.begin(), ans.end()));
    case  3: return std::distance(ans.begin(), std::min_element(ans.begin(), ans.end()));
    case  4: return std::distance(ans.begin(), std::min_element(ans.begin(), ans.end()));
    case  5: return std::distance(ans.begin(), std::max_element(ans.begin(), ans.end()));
    case  6: return std::distance(ans.begin(), std::max_element(ans.begin(), ans.end()));
    case  7: return std::distance(ans.begin(), std::max_element(ans.begin(), ans.end()));
    case  8: return std::distance(ans.begin(), std::max_element(ans.begin(), ans.end()));
    case  9: return std::distance(ans.begin(), std::max_element(ans.begin(), ans.end()));
    case 10: return std::distance(ans.begin(), std::max_element(ans.begin(), ans.end()));

  }

  return -1;

}


void merge_motif_pair_subworker(list_num_t mot1, list_num_t mot2,
    const std::string &method, const int minoverlap, vec_num_t ic1,
    vec_num_t ic2, const bool norm, const double posic, const double minic,
    double &score, int &offset, const double nsites1, const double nsites2,
    const vec_num_t &bkg1, const vec_num_t &bkg2) {

  std::size_t tlen = mot1.size() >= mot2.size() ? mot1.size() : mot2.size();

  equalize_mot_cols(mot1, mot2, ic1, ic2, minoverlap);

  std::size_t minw = mot1.size() <= mot2.size() ? mot1.size() : mot2.size();
  list_num_t tmot1(minw), tmot2(minw);
  vec_num_t tic1(minw), tic2(minw);
  std::size_t fori = 1 + mot1.size() - minw, forj = 1 + mot2.size() - minw;
  int alignlen;
  double mic1, mic2;
  bool lowic = false;
  vec_num_t ans(fori * forj);
  std::size_t counter = 0;

  for (std::size_t i = 0; i < fori; ++i) {
    for (std::size_t j = 0; j < forj; ++j) {

      for (std::size_t k = 0; k < minw; ++k) {
        tmot1[k] = mot1[k + i];
        tmot2[k] = mot2[k + j];
        tic1[k] = ic1[k + i];
        tic2[k] = ic2[k + j];
      }

      if (posic > 0) fix_lowic_pos(tmot1, tmot2, tic1, tic2, posic);

      alignlen = norm ? get_alignlen(tmot1, tmot2) : tlen;

      mic1 = calc_mic(tic1);
      mic2 = calc_mic(tic2);
      if (mic1 < minic || mic2 < minic) lowic = true;

      get_compare_ans(ans, counter, tmot1, tmot2, lowic, norm, alignlen, tlen,
          method, nsites1, nsites2, bkg1, bkg2);

      ++counter;
      lowic = false;

    }
  }

  score = return_best_ans(ans, method);
  offset = return_best_ans_which(ans, method);

}

list_num_t add_motif_columns(const list_num_t &mot, const int tlen,
    const int add) {

  list_num_t out(tlen, vec_num_t(mot[0].size(), -1.0));
  int lenadd = add + int(mot.size());
  int counter = 0;
  for (int i = add; i < lenadd; ++i) {
    out[i] = mot[counter];
    ++counter;
  }

  return out;

}

list_num_t merge_motif_pair(list_num_t mot1, list_num_t mot2,
    const std::string &method, const int minoverlap, const bool RC,
    vec_num_t ic1, vec_num_t ic2, const int weight,
    const bool norm, const double posic, const double minic,
    const double nsites1, const double nsites2, const vec_num_t &bkg1,
    const vec_num_t &bkg2) {

  double score;
  int offset;

  std::size_t ncol1 = mot1.size();
  std::size_t ncol2 = mot2.size();
  std::size_t overlap1 = minoverlap, overlap2 = minoverlap;

  if (minoverlap < 1) {
    overlap1 *= ncol1;
    overlap2 *= ncol2;
  }

  merge_motif_pair_subworker(mot1, mot2, method, minoverlap, ic1, ic2, norm,
      posic, minic, score, offset, nsites1, nsites2, bkg1, bkg2);

  if (RC) {
    double score_rc;
    int offset_rc;
    list_num_t rcmot2 = get_motif_rc(mot2);
    vec_num_t rcic2 = ic2;
    std::reverse(rcic2.begin(), rcic2.end());
    merge_motif_pair_subworker(mot1, rcmot2, method, minoverlap, ic1, rcic2,
        norm, posic, minic, score_rc, offset_rc, nsites1, nsites2, bkg1, bkg2);
    if (score_rc > score) {
      offset = offset_rc;
      mot2 = rcmot2;
    }
  }

  equalize_mot_cols(mot1, mot2, ic1, ic2, minoverlap);

  int ncol1t = mot1.size(), ncol2t = mot2.size();
  int minw = ncol1 <= ncol2 ? ncol1 : ncol2;
  int total = (1 + ncol1 - minw) * (1 + ncol2 - minw);
  int add1 = offset / total, add2 = offset % total;
  int tlen = ncol1t >= ncol2t ? ncol1t : ncol2t;

  if (ncol2t > ncol1t) {
    mot1 = add_motif_columns(mot1, tlen, abs(add2 - add1));
  } else if (ncol1t > ncol2t) {
    mot2 = add_motif_columns(mot2, tlen, abs(add1 - add2));
  }

  list_num_t merged = get_merged_motif(mot1, mot2, weight);

  return merged;

}

vec_num_t merge_bkg_pair(const vec_num_t &bkg1, const vec_num_t &bkg2,
    const int weight) {

  vec_num_t newbkg(bkg1.size());

  for (std::size_t i = 0; i < bkg1.size(); ++i) {
    newbkg[i] = (bkg1[i] * double(weight) + bkg2[i]) / (double(weight) + 1);
  }

  return newbkg;

}

vec_num_t calc_ic_motif(const list_num_t &motif, const vec_num_t &bkg,
    const bool relative) {

  vec_num_t out(motif.size());
  for (std::size_t i = 0; i < motif.size(); ++i) {
    out[i] = internal_posIC(motif[i], bkg, 1, relative);
  }

  return out;

}

void find_offsets(list_num_t mot1, list_num_t mot2, int &offset_1,
    int &offset_2, bool &use_rc, const std::string &method, const int minoverlap,
    vec_num_t ic1, vec_num_t ic2, const bool norm, const double posic,
    const double minic, const bool RC, const double nsites1, const double nsites2,
    const vec_num_t &bkg1, const vec_num_t &bkg2) {

  double score;
  int offset;

  std::size_t ncol1 = mot1.size();
  std::size_t ncol2 = mot2.size();
  std::size_t overlap1 = minoverlap, overlap2 = minoverlap;

  if (minoverlap < 1) {
    overlap1 *= ncol1;
    overlap2 *= ncol2;
  }

  merge_motif_pair_subworker(mot1, mot2, method, minoverlap, ic1, ic2, norm,
      posic, minic, score, offset, nsites1, nsites2, bkg1, bkg2);

  if (RC) {
    double score_rc;
    int offset_rc;
    list_num_t rcmot2 = get_motif_rc(mot2);
    vec_num_t rcic2 = ic2;
    std::reverse(rcic2.begin(), rcic2.end());
    merge_motif_pair_subworker(mot1, rcmot2, method, minoverlap, ic1, rcic2,
        norm, posic, minic, score_rc, offset_rc, nsites1, nsites2, bkg1, bkg2);
    if (score_rc > score) {
      offset = offset_rc;
      mot2 = rcmot2;
      use_rc = true;
    }
  }

  equalize_mot_cols(mot1, mot2, ic1, ic2, minoverlap);

  int minw = ncol1 <= ncol2 ? ncol1 : ncol2;
  int total = (1 + ncol1 - minw) * (1 + ncol2 - minw);
  int add1 = offset / total, add2 = offset % total;

  int ncol1t = mot1.size(), ncol2t = mot2.size();
  if (ncol2t > ncol1t) {
    offset_1 = abs(add2 - add1);
  } else if (ncol1t > ncol2t) {
    offset_2 = abs(add1 - add2);
  }

  return;

}

void neg_one_to_zero(list_num_t &mot) {

  for (std::size_t i = 0; i < mot.size(); ++i) {
    for (std::size_t j = 0; j < mot[0].size(); ++j) {
      if (mot[i][j] < 0) mot[i][j] = 0;
    }
  }

  return;

}

/* C++ ENTRY ---------------------------------------------------------------- */

// [[Rcpp::export(rng = false)]]
std::vector<double> compare_motifs_cpp(const Rcpp::List &mots,
    const std::vector<int> &index1, const std::vector<int> &index2,
    const std::string &method, int minoverlap, const bool RC,
    std::vector<std::vector<double>> &bkg, const int type, const bool relative,
    const double minic, const bool norm, const int nthreads, const double posic,
    const std::vector<double> &nsites) {

  /* compare motifs by indices, i.e. mots[index1[i]] vs mots[index2[i]] */

  if (minoverlap < 1) minoverlap = 1;

  if (type != 1 && type != 2)
    Rcpp::stop("type must be 1 or 2");
  if (minic < 0)
    Rcpp::stop("min.mean.ic must be positive");
  if (posic < 0)
    Rcpp::stop("min.position.ic must be positive");
  if (mots.size() == 0)
    Rcpp::stop("empty motif list");
  if (bkg.size() == 0)
    Rcpp::stop("empty bkg list");
  if (int(mots.size()) != int(bkg.size()))
    Rcpp::stop("different motif and bkg lengths");
  if (index1.size() != index2.size())
    Rcpp::stop("lengths of indices do not match [compare_motifs_cpp()]");

  list_nmat_t vmots(bkg.size());
  list_num_t icscores(vmots.size());

  for (std::size_t i = 0; i < vmots.size(); ++i) {
    Rcpp::NumericMatrix tmp = mots(i);
    vmots[i] = R_to_cpp_motif_num(tmp);
    if (vmots[i].size() == 0)
      Rcpp::stop("encountered an empty motif [compare_motifs_cpp()]");
    switch (::METRICS_enum[method]) {
      case 3:
      case 4:
      case 9:
      case 10: klfix(vmots[i]);
               bkgfix(bkg[i]);
    }
  }

  for (std::size_t i = 0; i < vmots.size(); ++i) {
    icscores[i].reserve(vmots[i].size());
    for (std::size_t j = 0; j < vmots[i].size(); ++j) {
      icscores[i].push_back(internal_posIC(vmots[i][j], bkg[i], type, relative));
    }
  }

  vec_num_t answers(index1.size());
  RcppThread::parallelFor(0, answers.size(),
      [&answers, &vmots, &index1, &index2, &icscores, &method, minoverlap, RC,
        minic, norm, posic, &bkg, &nsites]
      (std::size_t i) {
        answers[i] = compare_motif_pair(vmots[index1[i]], vmots[index2[i]],
            method, minoverlap, RC, icscores[index1[i]], icscores[index2[i]],
            minic, norm, posic, bkg[index1[i]], bkg[index1[i]], nsites[index1[i]],
            nsites[index2[i]]);
      }, nthreads);

  return answers;

}

// [[Rcpp::export(rng = false)]]
std::vector<std::vector<double>> compare_motifs_all_cpp(const Rcpp::List &mots,
    const std::string &method, int minoverlap, const bool RC,
    std::vector<std::vector<double>> &bkg, const int type, const bool relative,
    const double minic, const bool norm, const int nthreads, const double posic,
    const std::vector<double> &nsites) {

  /* compare all motifs to all motifs (without comparing the same motifs twice) */

  if (minoverlap < 1) minoverlap = 1;

  if (type != 1 && type != 2)
    Rcpp::stop("type must be 1 or 2");
  if (minic < 0)
    Rcpp::stop("min.mean.ic must be positive");
  if (posic < 0)
    Rcpp::stop("min.position.ic must be positive");
  if (mots.size() == 0)
    Rcpp::stop("empty motif list");
  if (bkg.size() == 0)
    Rcpp::stop("empty bkg list");
  if (int(mots.size()) != int(bkg.size()))
    Rcpp::stop("different motif and bkg lengths");

  list_nmat_t vmots(bkg.size());
  list_num_t icscores(vmots.size());

  for (std::size_t i = 0; i < vmots.size(); ++i) {
    Rcpp::NumericMatrix tmp = mots(i);
    vmots[i] = R_to_cpp_motif_num(tmp);
    if (vmots[i].size() == 0)
      Rcpp::stop("encountered an empty motif [compare_motifs_all_cpp()]");
    switch (::METRICS_enum[method]) {
      case 3:
      case 4:
      case 9:
      case 10: klfix(vmots[i]);
               bkgfix(bkg[i]);
    }
  }

  for (std::size_t i = 0; i < vmots.size(); ++i) {
    icscores[i].reserve(vmots[i].size());
    for (std::size_t j = 0; j < vmots[i].size(); ++j) {
      icscores[i].push_back(internal_posIC(vmots[i][j], bkg[i], type, relative));
    }
  }

  list_num_t answers(vmots.size());
  RcppThread::parallelFor(0, answers.size() - 1,
      [&answers, &vmots, &icscores, &method, minoverlap, RC, minic, norm, posic,
      &bkg, &nsites]
      (std::size_t i) {
        answers[i].reserve(vmots.size() - i + 1);
        for (std::size_t j = i + 1; j < vmots.size(); ++j) {
          answers[i].push_back(compare_motif_pair(vmots[i], vmots[j], method,
              minoverlap, RC, icscores[i], icscores[j], minic, norm, posic,
              bkg[i], bkg[j], nsites[i], nsites[j]));
        }
      }, nthreads);

  return answers;

}

// [[Rcpp::export(rng = false)]]
Rcpp::NumericMatrix get_comparison_matrix(const std::vector<double> &ans,
    const std::vector<int> &index1, const std::vector<int> &index2,
    const std::string &method, const Rcpp::StringVector &motnames) {

  /* convert the output from compare_motifs_all_cpp() to a matrix */

  Rcpp::NumericMatrix out(motnames.size(), motnames.size());

  switch (::METRICS_enum[method]) {
    case  6: out.fill_diag(1.0);
             break;
    case  8: out.fill_diag(2.0);
             break;
    case 10: out.fill_diag(1.314);
             break;
    default: out.fill_diag(0.0);
             break;
  }

  for (std::size_t i = 0; i < ans.size(); ++i) {
    out(index1[i], index2[i]) = ans[i];
    out(index2[i], index1[i]) = ans[i];
  }

  Rcpp::rownames(out) = motnames;
  Rcpp::colnames(out) = motnames;

  return out;

}

// [[Rcpp::export(rng = false)]]
Rcpp::List view_motifs_prep(const Rcpp::List &mots, const std::string &method,
    const bool RC, int minoverlap, const double minic, const double posic,
    std::vector<std::vector<double>> &bkg, const bool relative, const bool norm,
    const Rcpp::StringVector &rnames, const std::vector<double> &nsites) {

  if (minoverlap < 1) minoverlap = 1;
  if (minic < 0)
    Rcpp::stop("min.mean.ic must be positive");
  if (posic < 0)
    Rcpp::stop("min.position.ic must be positive");
  if (mots.size() == 0)
    Rcpp::stop("empty motif list");

  list_nmat_t vmots(mots.size());
  list_num_t icscores(vmots.size());
  vec_int_t motlens(mots.size());

  for (std::size_t i = 0; i < vmots.size(); ++i) {
    Rcpp::NumericMatrix tmp = mots(i);
    vmots[i] = R_to_cpp_motif_num(tmp);
    if (vmots[i].size() == 0)
      Rcpp::stop("encountered an empty motif [compare_motifs_all_cpp()]");
    motlens[i] = vmots[i].size();
    switch (::METRICS_enum[method]) {
      case 3:
      case 4:
      case 9:
      case 10: klfix(vmots[i]);
               bkgfix(bkg[i]);
    }
  }

  for (std::size_t i = 0; i < vmots.size(); ++i) {
    icscores[i] = calc_ic_motif(vmots[i], bkg[i], relative);
  }

  vec_bool_t which_rc(vmots.size(), false);
  vec_int_t offsets_1(vmots.size(), 0);
  vec_int_t offsets_2(vmots.size(), 0);

  int off1 = 0, off2 = 0; bool rc_ = false;
  for (std::size_t i = 1; i < vmots.size(); ++i) {

    off1 = 0; off2 = 0; rc_ = false;

    find_offsets(vmots[0], vmots[i], off1, off2, rc_, method, minoverlap,
        icscores[0], icscores[i], norm, posic, minic, RC, nsites[0], nsites[i],
        bkg[0], bkg[i]);

    offsets_1[i] = off1;
    offsets_2[i] = off2;
    which_rc[i] = rc_;

  }

  for (std::size_t i = 1; i < which_rc.size(); ++i) {
    if (which_rc[i]) vmots[i] = get_motif_rc(vmots[i]);
  }

  vec_int_t motlens2(vmots.size());
  for (std::size_t i = 0; i < vmots.size(); ++i) {
    motlens2[i] = motlens[i] + offsets_2[i];
  }

  int tlen = *std::max_element(motlens2.begin(), motlens2.end());
  tlen += *std::max_element(offsets_1.begin(), offsets_1.end());

  Rcpp::List motlist(vmots.size());
  for (std::size_t i = 0; i < vmots.size(); ++i) {
    vmots[i] = add_motif_columns(vmots[i], tlen,
        offsets_2[i] + *std::max_element(offsets_1.begin(), offsets_1.end()) - offsets_1[i]);
    neg_one_to_zero(vmots[i]);
    Rcpp::NumericMatrix tmp = cpp_to_R_motif(vmots[i]);
    rownames(tmp) = rnames;
    motlist[i] = tmp;
  }

  return Rcpp::List::create(
        Rcpp::_["motIsRC"] = which_rc,
        Rcpp::_["motifs"] = motlist
      );

}

// [[Rcpp::export(rng = false)]]
Rcpp::List merge_motifs_cpp(const Rcpp::List &mots,
    const std::string &method, const bool RC, int minoverlap, const double minic,
    const double posic, std::vector<std::vector<double>> &bkg,
    const bool relative, const bool norm, const std::vector<double> &nsites) {

  /* merge a list of motifs, as well as their backgrounds */

  if (minoverlap < 1) minoverlap = 1;
  if (minic < 0)
    Rcpp::stop("min.mean.ic must be positive");
  if (posic < 0)
    Rcpp::stop("min.position.ic must be positive");
  if (mots.size() == 0)
    Rcpp::stop("empty motif list");

  list_nmat_t vmots(mots.size());
  list_num_t icscores(vmots.size());

  for (std::size_t i = 0; i < vmots.size(); ++i) {
    Rcpp::NumericMatrix tmp = mots(i);
    vmots[i] = R_to_cpp_motif_num(tmp);
    if (vmots[i].size() == 0)
      Rcpp::stop("encountered an empty motif [compare_motifs_all_cpp()]");
    switch (::METRICS_enum[method]) {
      case 3:
      case 4:
      case 9:
      case 10: klfix(vmots[i]);
               bkgfix(bkg[i]);
    }
  }

  for (std::size_t i = 0; i < vmots.size(); ++i) {
    icscores[i].reserve(vmots[i].size());
    for (std::size_t j = 0; j < vmots[i].size(); ++j) {
      icscores[i].push_back(internal_posIC(vmots[i][j], bkg[i], 1, relative));
    }
  }

  int weight = 1;
  // double nnsites = nsites[0] > nsites[1] ? nsites[0] : nsites[1];
  double nnsites = nsites[0] + nsites[1];
  list_num_t merged = merge_motif_pair(vmots[0], vmots[1], method, minoverlap,
      RC, icscores[0], icscores[1], weight, norm, posic, minic, nsites[0],
      nsites[1], bkg[0], bkg[1]);
  vec_num_t mergedbkg = merge_bkg_pair(bkg[0], bkg[1], weight);
  vec_num_t mergedic = calc_ic_motif(merged, mergedbkg, relative);

  if (vmots.size() > 2) {
    for (std::size_t i = 2; i < vmots.size(); ++i) {
      ++weight;
      merged = merge_motif_pair(merged, vmots[i], method, minoverlap, RC,
          mergedic, icscores[i], weight, norm, posic, minic, nnsites,
          nsites[i], mergedbkg, bkg[i]);
      mergedbkg = merge_bkg_pair(mergedbkg, bkg[i], weight);
      mergedic = calc_ic_motif(merged, mergedbkg, relative);
      nnsites += nsites[i];
      // nnsites = nnsites > nsites[i] ? nnsites : nsites[i];
    }
  }

  Rcpp::NumericMatrix outmotif = cpp_to_R_motif(merged);
  Rcpp::NumericVector outbkg = Rcpp::wrap(mergedbkg);

  return Rcpp::List::create(outmotif, outbkg);

}

// [[Rcpp::export(rng = false)]]
double compare_columns_cpp(const std::vector<double> &p1,
    const std::vector<double> &p2, const std::vector<double> &b1,
    const std::vector<double> &b2, const double n1 = 100,
    const double n2 = 100, const std::string &m = "PCC") {

  if (p1.size() < 2) Rcpp::stop("columns should have at least 2 entries");
  if (p1.size() != p2.size()) Rcpp::stop("both columns must be equal in size");

  list_num_t pp1(1), pp2(1);
  pp1[0] = p1; pp2[0] = p2;

  double ans;

  switch (::METRICS_enum[m]) {
    case 1: ans = compare_eucl(pp1, pp2);
            break;
    case 3: ans = compare_kl(pp1, pp2);
            break;
    case 5: ans = compare_pcc(pp1, pp2);
            break;
    case 7: ans = compare_sw(pp1, pp2);
            break;
    case 9: if (b1.size() != p1.size() || b2.size() != p1.size())
              Rcpp::stop("incorrect background vector length");
            if (n1 <= 1 || n2 <= 1)
              Rcpp::stop("nsites1/nsites2 should be greater than 1");
            ans = compare_allr(pp1, pp2, b1, b2, n1, n2);
            break;
    default: Rcpp::stop("unknown metric");
  }

  return ans;

}
