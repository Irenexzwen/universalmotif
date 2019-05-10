// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// single_to_k
StringVector single_to_k(StringVector seq1, int k);
RcppExport SEXP _universalmotif_single_to_k(SEXP seq1SEXP, SEXP kSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< StringVector >::type seq1(seq1SEXP);
    Rcpp::traits::input_parameter< int >::type k(kSEXP);
    rcpp_result_gen = Rcpp::wrap(single_to_k(seq1, k));
    return rcpp_result_gen;
END_RCPP
}
// peakfinder_cpp
IntegerVector peakfinder_cpp(const NumericVector& x, int m);
RcppExport SEXP _universalmotif_peakfinder_cpp(SEXP xSEXP, SEXP mSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< const NumericVector& >::type x(xSEXP);
    Rcpp::traits::input_parameter< int >::type m(mSEXP);
    rcpp_result_gen = Rcpp::wrap(peakfinder_cpp(x, m));
    return rcpp_result_gen;
END_RCPP
}
// linbin_cpp
IntegerVector linbin_cpp(const IntegerVector& x, const IntegerVector& gpoints);
RcppExport SEXP _universalmotif_linbin_cpp(SEXP xSEXP, SEXP gpointsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< const IntegerVector& >::type x(xSEXP);
    Rcpp::traits::input_parameter< const IntegerVector& >::type gpoints(gpointsSEXP);
    rcpp_result_gen = Rcpp::wrap(linbin_cpp(x, gpoints));
    return rcpp_result_gen;
END_RCPP
}
// calc_scores_cpp
IntegerVector calc_scores_cpp(const IntegerMatrix& paths, const IntegerMatrix& score_mat);
RcppExport SEXP _universalmotif_calc_scores_cpp(SEXP pathsSEXP, SEXP score_matSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< const IntegerMatrix& >::type paths(pathsSEXP);
    Rcpp::traits::input_parameter< const IntegerMatrix& >::type score_mat(score_matSEXP);
    rcpp_result_gen = Rcpp::wrap(calc_scores_cpp(paths, score_mat));
    return rcpp_result_gen;
END_RCPP
}
// kmer_mat_to_probs_k1_cpp
NumericVector kmer_mat_to_probs_k1_cpp(const IntegerMatrix& bb_mat, const NumericVector& bkg, const IntegerMatrix& alph_sort);
RcppExport SEXP _universalmotif_kmer_mat_to_probs_k1_cpp(SEXP bb_matSEXP, SEXP bkgSEXP, SEXP alph_sortSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< const IntegerMatrix& >::type bb_mat(bb_matSEXP);
    Rcpp::traits::input_parameter< const NumericVector& >::type bkg(bkgSEXP);
    Rcpp::traits::input_parameter< const IntegerMatrix& >::type alph_sort(alph_sortSEXP);
    rcpp_result_gen = Rcpp::wrap(kmer_mat_to_probs_k1_cpp(bb_mat, bkg, alph_sort));
    return rcpp_result_gen;
END_RCPP
}
// init_paths_cpp
IntegerMatrix init_paths_cpp(const IntegerMatrix& score_mat, int score, int max_score);
RcppExport SEXP _universalmotif_init_paths_cpp(SEXP score_matSEXP, SEXP scoreSEXP, SEXP max_scoreSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< const IntegerMatrix& >::type score_mat(score_matSEXP);
    Rcpp::traits::input_parameter< int >::type score(scoreSEXP);
    Rcpp::traits::input_parameter< int >::type max_score(max_scoreSEXP);
    rcpp_result_gen = Rcpp::wrap(init_paths_cpp(score_mat, score, max_score));
    return rcpp_result_gen;
END_RCPP
}
// list_to_matrix
IntegerMatrix list_to_matrix(const List& paths);
RcppExport SEXP _universalmotif_list_to_matrix(SEXP pathsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< const List& >::type paths(pathsSEXP);
    rcpp_result_gen = Rcpp::wrap(list_to_matrix(paths));
    return rcpp_result_gen;
END_RCPP
}
// calc_next_path_cpp
IntegerMatrix calc_next_path_cpp(const IntegerMatrix& score_mat, const IntegerMatrix& paths, int score, int max_score);
RcppExport SEXP _universalmotif_calc_next_path_cpp(SEXP score_matSEXP, SEXP pathsSEXP, SEXP scoreSEXP, SEXP max_scoreSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< const IntegerMatrix& >::type score_mat(score_matSEXP);
    Rcpp::traits::input_parameter< const IntegerMatrix& >::type paths(pathsSEXP);
    Rcpp::traits::input_parameter< int >::type score(scoreSEXP);
    Rcpp::traits::input_parameter< int >::type max_score(max_scoreSEXP);
    rcpp_result_gen = Rcpp::wrap(calc_next_path_cpp(score_mat, paths, score, max_score));
    return rcpp_result_gen;
END_RCPP
}
// expand_scores
IntegerVector expand_scores(const IntegerMatrix& scores);
RcppExport SEXP _universalmotif_expand_scores(SEXP scoresSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< const IntegerMatrix& >::type scores(scoresSEXP);
    rcpp_result_gen = Rcpp::wrap(expand_scores(scores));
    return rcpp_result_gen;
END_RCPP
}
// paths_alph_unsort
IntegerMatrix paths_alph_unsort(IntegerMatrix paths, const IntegerMatrix& alph);
RcppExport SEXP _universalmotif_paths_alph_unsort(SEXP pathsSEXP, SEXP alphSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< IntegerMatrix >::type paths(pathsSEXP);
    Rcpp::traits::input_parameter< const IntegerMatrix& >::type alph(alphSEXP);
    rcpp_result_gen = Rcpp::wrap(paths_alph_unsort(paths, alph));
    return rcpp_result_gen;
END_RCPP
}
// paths_to_alph
StringVector paths_to_alph(const IntegerMatrix& paths, const StringVector& alph);
RcppExport SEXP _universalmotif_paths_to_alph(SEXP pathsSEXP, SEXP alphSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< const IntegerMatrix& >::type paths(pathsSEXP);
    Rcpp::traits::input_parameter< const StringVector& >::type alph(alphSEXP);
    rcpp_result_gen = Rcpp::wrap(paths_to_alph(paths, alph));
    return rcpp_result_gen;
END_RCPP
}
// add_cols
List add_cols(const NumericMatrix& mot1, const NumericMatrix& mot2, const NumericVector& ic1, const NumericVector& ic2, double overlap);
RcppExport SEXP _universalmotif_add_cols(SEXP mot1SEXP, SEXP mot2SEXP, SEXP ic1SEXP, SEXP ic2SEXP, SEXP overlapSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< const NumericMatrix& >::type mot1(mot1SEXP);
    Rcpp::traits::input_parameter< const NumericMatrix& >::type mot2(mot2SEXP);
    Rcpp::traits::input_parameter< const NumericVector& >::type ic1(ic1SEXP);
    Rcpp::traits::input_parameter< const NumericVector& >::type ic2(ic2SEXP);
    Rcpp::traits::input_parameter< double >::type overlap(overlapSEXP);
    rcpp_result_gen = Rcpp::wrap(add_cols(mot1, mot2, ic1, ic2, overlap));
    return rcpp_result_gen;
END_RCPP
}
// motif_simil_internal
double motif_simil_internal(NumericMatrix mot1, NumericMatrix mot2, String method, double min_overlap, bool tryRC, NumericVector ic1, NumericVector ic2, double min_ic, bool norm);
RcppExport SEXP _universalmotif_motif_simil_internal(SEXP mot1SEXP, SEXP mot2SEXP, SEXP methodSEXP, SEXP min_overlapSEXP, SEXP tryRCSEXP, SEXP ic1SEXP, SEXP ic2SEXP, SEXP min_icSEXP, SEXP normSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< NumericMatrix >::type mot1(mot1SEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type mot2(mot2SEXP);
    Rcpp::traits::input_parameter< String >::type method(methodSEXP);
    Rcpp::traits::input_parameter< double >::type min_overlap(min_overlapSEXP);
    Rcpp::traits::input_parameter< bool >::type tryRC(tryRCSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type ic1(ic1SEXP);
    Rcpp::traits::input_parameter< NumericVector >::type ic2(ic2SEXP);
    Rcpp::traits::input_parameter< double >::type min_ic(min_icSEXP);
    Rcpp::traits::input_parameter< bool >::type norm(normSEXP);
    rcpp_result_gen = Rcpp::wrap(motif_simil_internal(mot1, mot2, method, min_overlap, tryRC, ic1, ic2, min_ic, norm));
    return rcpp_result_gen;
END_RCPP
}
// list_to_matrix_simil
NumericMatrix list_to_matrix_simil(List comparisons, StringVector mot_names, String method);
RcppExport SEXP _universalmotif_list_to_matrix_simil(SEXP comparisonsSEXP, SEXP mot_namesSEXP, SEXP methodSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< List >::type comparisons(comparisonsSEXP);
    Rcpp::traits::input_parameter< StringVector >::type mot_names(mot_namesSEXP);
    Rcpp::traits::input_parameter< String >::type method(methodSEXP);
    rcpp_result_gen = Rcpp::wrap(list_to_matrix_simil(comparisons, mot_names, method));
    return rcpp_result_gen;
END_RCPP
}
// merge_add_cols
List merge_add_cols(List out);
RcppExport SEXP _universalmotif_merge_add_cols(SEXP outSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< List >::type out(outSEXP);
    rcpp_result_gen = Rcpp::wrap(merge_add_cols(out));
    return rcpp_result_gen;
END_RCPP
}
// merge_motifs_get_offset
List merge_motifs_get_offset(NumericMatrix mot1, NumericMatrix mot2, String method, double min_overlap, NumericVector ic1, NumericVector ic2, double min_ic, bool norm);
RcppExport SEXP _universalmotif_merge_motifs_get_offset(SEXP mot1SEXP, SEXP mot2SEXP, SEXP methodSEXP, SEXP min_overlapSEXP, SEXP ic1SEXP, SEXP ic2SEXP, SEXP min_icSEXP, SEXP normSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< NumericMatrix >::type mot1(mot1SEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type mot2(mot2SEXP);
    Rcpp::traits::input_parameter< String >::type method(methodSEXP);
    Rcpp::traits::input_parameter< double >::type min_overlap(min_overlapSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type ic1(ic1SEXP);
    Rcpp::traits::input_parameter< NumericVector >::type ic2(ic2SEXP);
    Rcpp::traits::input_parameter< double >::type min_ic(min_icSEXP);
    Rcpp::traits::input_parameter< bool >::type norm(normSEXP);
    rcpp_result_gen = Rcpp::wrap(merge_motifs_get_offset(mot1, mot2, method, min_overlap, ic1, ic2, min_ic, norm));
    return rcpp_result_gen;
END_RCPP
}
// merge_motifs_internal
NumericMatrix merge_motifs_internal(NumericMatrix mot1, NumericMatrix mot2, String method, double min_overlap, bool tryRC, NumericVector ic1, NumericVector ic2, double min_ic, double weight1, double weight2, bool norm);
RcppExport SEXP _universalmotif_merge_motifs_internal(SEXP mot1SEXP, SEXP mot2SEXP, SEXP methodSEXP, SEXP min_overlapSEXP, SEXP tryRCSEXP, SEXP ic1SEXP, SEXP ic2SEXP, SEXP min_icSEXP, SEXP weight1SEXP, SEXP weight2SEXP, SEXP normSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< NumericMatrix >::type mot1(mot1SEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type mot2(mot2SEXP);
    Rcpp::traits::input_parameter< String >::type method(methodSEXP);
    Rcpp::traits::input_parameter< double >::type min_overlap(min_overlapSEXP);
    Rcpp::traits::input_parameter< bool >::type tryRC(tryRCSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type ic1(ic1SEXP);
    Rcpp::traits::input_parameter< NumericVector >::type ic2(ic2SEXP);
    Rcpp::traits::input_parameter< double >::type min_ic(min_icSEXP);
    Rcpp::traits::input_parameter< double >::type weight1(weight1SEXP);
    Rcpp::traits::input_parameter< double >::type weight2(weight2SEXP);
    Rcpp::traits::input_parameter< bool >::type norm(normSEXP);
    rcpp_result_gen = Rcpp::wrap(merge_motifs_internal(mot1, mot2, method, min_overlap, tryRC, ic1, ic2, min_ic, weight1, weight2, norm));
    return rcpp_result_gen;
END_RCPP
}
// scan_sequences_cpp
Rcpp::DataFrame scan_sequences_cpp(const Rcpp::List& score_mats, const std::vector<std::string>& seq_vecs, const int& k, const std::string& alph, const std::vector<double>& min_scores, const int& nthreads);
RcppExport SEXP _universalmotif_scan_sequences_cpp(SEXP score_matsSEXP, SEXP seq_vecsSEXP, SEXP kSEXP, SEXP alphSEXP, SEXP min_scoresSEXP, SEXP nthreadsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< const Rcpp::List& >::type score_mats(score_matsSEXP);
    Rcpp::traits::input_parameter< const std::vector<std::string>& >::type seq_vecs(seq_vecsSEXP);
    Rcpp::traits::input_parameter< const int& >::type k(kSEXP);
    Rcpp::traits::input_parameter< const std::string& >::type alph(alphSEXP);
    Rcpp::traits::input_parameter< const std::vector<double>& >::type min_scores(min_scoresSEXP);
    Rcpp::traits::input_parameter< const int& >::type nthreads(nthreadsSEXP);
    rcpp_result_gen = Rcpp::wrap(scan_sequences_cpp(score_mats, seq_vecs, k, alph, min_scores, nthreads));
    return rcpp_result_gen;
END_RCPP
}
// shuffle_markov_cpp
std::vector<std::string> shuffle_markov_cpp(const std::vector<std::string>& sequences, const int& k, const int& nthreads, const int& seed);
RcppExport SEXP _universalmotif_shuffle_markov_cpp(SEXP sequencesSEXP, SEXP kSEXP, SEXP nthreadsSEXP, SEXP seedSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< const std::vector<std::string>& >::type sequences(sequencesSEXP);
    Rcpp::traits::input_parameter< const int& >::type k(kSEXP);
    Rcpp::traits::input_parameter< const int& >::type nthreads(nthreadsSEXP);
    Rcpp::traits::input_parameter< const int& >::type seed(seedSEXP);
    rcpp_result_gen = Rcpp::wrap(shuffle_markov_cpp(sequences, k, nthreads, seed));
    return rcpp_result_gen;
END_RCPP
}
// shuffle_euler_cpp
std::vector<std::string> shuffle_euler_cpp(const std::vector<std::string>& sequences, const int& k, const int& nthreads, const int& seed);
RcppExport SEXP _universalmotif_shuffle_euler_cpp(SEXP sequencesSEXP, SEXP kSEXP, SEXP nthreadsSEXP, SEXP seedSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< const std::vector<std::string>& >::type sequences(sequencesSEXP);
    Rcpp::traits::input_parameter< const int& >::type k(kSEXP);
    Rcpp::traits::input_parameter< const int& >::type nthreads(nthreadsSEXP);
    Rcpp::traits::input_parameter< const int& >::type seed(seedSEXP);
    rcpp_result_gen = Rcpp::wrap(shuffle_euler_cpp(sequences, k, nthreads, seed));
    return rcpp_result_gen;
END_RCPP
}
// shuffle_linear_cpp
std::vector<std::string> shuffle_linear_cpp(const std::vector<std::string>& sequences, const int& k, const int& nthreads, const int& seed);
RcppExport SEXP _universalmotif_shuffle_linear_cpp(SEXP sequencesSEXP, SEXP kSEXP, SEXP nthreadsSEXP, SEXP seedSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< const std::vector<std::string>& >::type sequences(sequencesSEXP);
    Rcpp::traits::input_parameter< const int& >::type k(kSEXP);
    Rcpp::traits::input_parameter< const int& >::type nthreads(nthreadsSEXP);
    Rcpp::traits::input_parameter< const int& >::type seed(seedSEXP);
    rcpp_result_gen = Rcpp::wrap(shuffle_linear_cpp(sequences, k, nthreads, seed));
    return rcpp_result_gen;
END_RCPP
}
// shuffle_k1_cpp
std::vector<std::string> shuffle_k1_cpp(const std::vector<std::string>& sequences, const int& nthreads, const int& seed);
RcppExport SEXP _universalmotif_shuffle_k1_cpp(SEXP sequencesSEXP, SEXP nthreadsSEXP, SEXP seedSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< const std::vector<std::string>& >::type sequences(sequencesSEXP);
    Rcpp::traits::input_parameter< const int& >::type nthreads(nthreadsSEXP);
    Rcpp::traits::input_parameter< const int& >::type seed(seedSEXP);
    rcpp_result_gen = Rcpp::wrap(shuffle_k1_cpp(sequences, nthreads, seed));
    return rcpp_result_gen;
END_RCPP
}
// count_klets_cpp
std::vector<std::vector<int>> count_klets_cpp(const std::vector<std::string>& sequences, const int& k, const int& nthreads);
RcppExport SEXP _universalmotif_count_klets_cpp(SEXP sequencesSEXP, SEXP kSEXP, SEXP nthreadsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< const std::vector<std::string>& >::type sequences(sequencesSEXP);
    Rcpp::traits::input_parameter< const int& >::type k(kSEXP);
    Rcpp::traits::input_parameter< const int& >::type nthreads(nthreadsSEXP);
    rcpp_result_gen = Rcpp::wrap(count_klets_cpp(sequences, k, nthreads));
    return rcpp_result_gen;
END_RCPP
}
// get_klets_cpp
std::vector<std::string> get_klets_cpp(std::vector<std::string>& alph, const int& k);
RcppExport SEXP _universalmotif_get_klets_cpp(SEXP alphSEXP, SEXP kSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< std::vector<std::string>& >::type alph(alphSEXP);
    Rcpp::traits::input_parameter< const int& >::type k(kSEXP);
    rcpp_result_gen = Rcpp::wrap(get_klets_cpp(alph, k));
    return rcpp_result_gen;
END_RCPP
}
// shuffle_markov_loop
Rcpp::String shuffle_markov_loop(R_xlen_t seq_i_l, R_xlen_t seq_i_r, int k, Rcpp::StringVector seqout, const Rcpp::StringVector& lets, const Rcpp::NumericMatrix& trans, const Rcpp::StringVector& trans_cols);
RcppExport SEXP _universalmotif_shuffle_markov_loop(SEXP seq_i_lSEXP, SEXP seq_i_rSEXP, SEXP kSEXP, SEXP seqoutSEXP, SEXP letsSEXP, SEXP transSEXP, SEXP trans_colsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< R_xlen_t >::type seq_i_l(seq_i_lSEXP);
    Rcpp::traits::input_parameter< R_xlen_t >::type seq_i_r(seq_i_rSEXP);
    Rcpp::traits::input_parameter< int >::type k(kSEXP);
    Rcpp::traits::input_parameter< Rcpp::StringVector >::type seqout(seqoutSEXP);
    Rcpp::traits::input_parameter< const Rcpp::StringVector& >::type lets(letsSEXP);
    Rcpp::traits::input_parameter< const Rcpp::NumericMatrix& >::type trans(transSEXP);
    Rcpp::traits::input_parameter< const Rcpp::StringVector& >::type trans_cols(trans_colsSEXP);
    rcpp_result_gen = Rcpp::wrap(shuffle_markov_loop(seq_i_l, seq_i_r, k, seqout, lets, trans, trans_cols));
    return rcpp_result_gen;
END_RCPP
}
// trim_motif_internal
NumericMatrix trim_motif_internal(const NumericMatrix& motif, const NumericVector& ic_scores, double min_ic);
RcppExport SEXP _universalmotif_trim_motif_internal(SEXP motifSEXP, SEXP ic_scoresSEXP, SEXP min_icSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< const NumericMatrix& >::type motif(motifSEXP);
    Rcpp::traits::input_parameter< const NumericVector& >::type ic_scores(ic_scoresSEXP);
    Rcpp::traits::input_parameter< double >::type min_ic(min_icSEXP);
    rcpp_result_gen = Rcpp::wrap(trim_motif_internal(motif, ic_scores, min_ic));
    return rcpp_result_gen;
END_RCPP
}
// universalmotif_cpp
S4 universalmotif_cpp(NumericMatrix motif, String name, StringVector altname, StringVector family, StringVector organism, StringVector alphabet, StringVector type, NumericVector icscore, NumericVector nsites, double pseudocount, NumericVector bkg, NumericVector bkgsites, StringVector consensus, String strand, NumericVector pval, NumericVector qval, NumericVector eval, StringVector extrainfo);
RcppExport SEXP _universalmotif_universalmotif_cpp(SEXP motifSEXP, SEXP nameSEXP, SEXP altnameSEXP, SEXP familySEXP, SEXP organismSEXP, SEXP alphabetSEXP, SEXP typeSEXP, SEXP icscoreSEXP, SEXP nsitesSEXP, SEXP pseudocountSEXP, SEXP bkgSEXP, SEXP bkgsitesSEXP, SEXP consensusSEXP, SEXP strandSEXP, SEXP pvalSEXP, SEXP qvalSEXP, SEXP evalSEXP, SEXP extrainfoSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< NumericMatrix >::type motif(motifSEXP);
    Rcpp::traits::input_parameter< String >::type name(nameSEXP);
    Rcpp::traits::input_parameter< StringVector >::type altname(altnameSEXP);
    Rcpp::traits::input_parameter< StringVector >::type family(familySEXP);
    Rcpp::traits::input_parameter< StringVector >::type organism(organismSEXP);
    Rcpp::traits::input_parameter< StringVector >::type alphabet(alphabetSEXP);
    Rcpp::traits::input_parameter< StringVector >::type type(typeSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type icscore(icscoreSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type nsites(nsitesSEXP);
    Rcpp::traits::input_parameter< double >::type pseudocount(pseudocountSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type bkg(bkgSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type bkgsites(bkgsitesSEXP);
    Rcpp::traits::input_parameter< StringVector >::type consensus(consensusSEXP);
    Rcpp::traits::input_parameter< String >::type strand(strandSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type pval(pvalSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type qval(qvalSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type eval(evalSEXP);
    Rcpp::traits::input_parameter< StringVector >::type extrainfo(extrainfoSEXP);
    rcpp_result_gen = Rcpp::wrap(universalmotif_cpp(motif, name, altname, family, organism, alphabet, type, icscore, nsites, pseudocount, bkg, bkgsites, consensus, strand, pval, qval, eval, extrainfo));
    return rcpp_result_gen;
END_RCPP
}
// check_bkg_names
bool check_bkg_names(StringVector alph, std::string blet);
RcppExport SEXP _universalmotif_check_bkg_names(SEXP alphSEXP, SEXP bletSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< StringVector >::type alph(alphSEXP);
    Rcpp::traits::input_parameter< std::string >::type blet(bletSEXP);
    rcpp_result_gen = Rcpp::wrap(check_bkg_names(alph, blet));
    return rcpp_result_gen;
END_RCPP
}
// validObject_universalmotif
StringVector validObject_universalmotif(S4 motif, bool throw_error);
RcppExport SEXP _universalmotif_validObject_universalmotif(SEXP motifSEXP, SEXP throw_errorSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< S4 >::type motif(motifSEXP);
    Rcpp::traits::input_parameter< bool >::type throw_error(throw_errorSEXP);
    rcpp_result_gen = Rcpp::wrap(validObject_universalmotif(motif, throw_error));
    return rcpp_result_gen;
END_RCPP
}
// summarise_motifs_cpp
DataFrame summarise_motifs_cpp(List motifs);
RcppExport SEXP _universalmotif_summarise_motifs_cpp(SEXP motifsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< List >::type motifs(motifsSEXP);
    rcpp_result_gen = Rcpp::wrap(summarise_motifs_cpp(motifs));
    return rcpp_result_gen;
END_RCPP
}
// universalmotif_to_list
List universalmotif_to_list(S4 motif);
RcppExport SEXP _universalmotif_universalmotif_to_list(SEXP motifSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< S4 >::type motif(motifSEXP);
    rcpp_result_gen = Rcpp::wrap(universalmotif_to_list(motif));
    return rcpp_result_gen;
END_RCPP
}
// sort_unique_cpp
StringVector sort_unique_cpp(const StringVector& x);
RcppExport SEXP _universalmotif_sort_unique_cpp(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< const StringVector& >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(sort_unique_cpp(x));
    return rcpp_result_gen;
END_RCPP
}
// table_cpp
IntegerVector table_cpp(const StringVector& x);
RcppExport SEXP _universalmotif_table_cpp(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< const StringVector& >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(table_cpp(x));
    return rcpp_result_gen;
END_RCPP
}
// collapse_rows_mat
StringVector collapse_rows_mat(const CharacterMatrix& seqs_k);
RcppExport SEXP _universalmotif_collapse_rows_mat(SEXP seqs_kSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< const CharacterMatrix& >::type seqs_k(seqs_kSEXP);
    rcpp_result_gen = Rcpp::wrap(collapse_rows_mat(seqs_k));
    return rcpp_result_gen;
END_RCPP
}
// collapse_cols_mat
StringVector collapse_cols_mat(const CharacterMatrix& seqs_k);
RcppExport SEXP _universalmotif_collapse_cols_mat(SEXP seqs_kSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< const CharacterMatrix& >::type seqs_k(seqs_kSEXP);
    rcpp_result_gen = Rcpp::wrap(collapse_cols_mat(seqs_k));
    return rcpp_result_gen;
END_RCPP
}
// collapse_rows_df
StringVector collapse_rows_df(const DataFrame& seqs_k);
RcppExport SEXP _universalmotif_collapse_rows_df(SEXP seqs_kSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< const DataFrame& >::type seqs_k(seqs_kSEXP);
    rcpp_result_gen = Rcpp::wrap(collapse_rows_df(seqs_k));
    return rcpp_result_gen;
END_RCPP
}
// collapse_cpp
String collapse_cpp(const StringVector& x);
RcppExport SEXP _universalmotif_collapse_cpp(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< const StringVector& >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(collapse_cpp(x));
    return rcpp_result_gen;
END_RCPP
}
// print_pb
void print_pb(R_xlen_t out);
RcppExport SEXP _universalmotif_print_pb(SEXP outSEXP) {
BEGIN_RCPP
    Rcpp::traits::input_parameter< R_xlen_t >::type out(outSEXP);
    print_pb(out);
    return R_NilValue;
END_RCPP
}
// update_pb
void update_pb(R_xlen_t i, R_xlen_t max);
RcppExport SEXP _universalmotif_update_pb(SEXP iSEXP, SEXP maxSEXP) {
BEGIN_RCPP
    Rcpp::traits::input_parameter< R_xlen_t >::type i(iSEXP);
    Rcpp::traits::input_parameter< R_xlen_t >::type max(maxSEXP);
    update_pb(i, max);
    return R_NilValue;
END_RCPP
}
// all_checks_collapse
String all_checks_collapse(const StringVector& checks);
RcppExport SEXP _universalmotif_all_checks_collapse(SEXP checksSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< const StringVector& >::type checks(checksSEXP);
    rcpp_result_gen = Rcpp::wrap(all_checks_collapse(checks));
    return rcpp_result_gen;
END_RCPP
}
// pcm_to_ppmC
NumericVector pcm_to_ppmC(NumericVector position, double pseudocount);
RcppExport SEXP _universalmotif_pcm_to_ppmC(SEXP positionSEXP, SEXP pseudocountSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< NumericVector >::type position(positionSEXP);
    Rcpp::traits::input_parameter< double >::type pseudocount(pseudocountSEXP);
    rcpp_result_gen = Rcpp::wrap(pcm_to_ppmC(position, pseudocount));
    return rcpp_result_gen;
END_RCPP
}
// ppm_to_pcmC
NumericVector ppm_to_pcmC(NumericVector position, double nsites);
RcppExport SEXP _universalmotif_ppm_to_pcmC(SEXP positionSEXP, SEXP nsitesSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< NumericVector >::type position(positionSEXP);
    Rcpp::traits::input_parameter< double >::type nsites(nsitesSEXP);
    rcpp_result_gen = Rcpp::wrap(ppm_to_pcmC(position, nsites));
    return rcpp_result_gen;
END_RCPP
}
// ppm_to_pwmC
NumericVector ppm_to_pwmC(NumericVector position, NumericVector bkg, double pseudocount, NumericVector nsites);
RcppExport SEXP _universalmotif_ppm_to_pwmC(SEXP positionSEXP, SEXP bkgSEXP, SEXP pseudocountSEXP, SEXP nsitesSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< NumericVector >::type position(positionSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type bkg(bkgSEXP);
    Rcpp::traits::input_parameter< double >::type pseudocount(pseudocountSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type nsites(nsitesSEXP);
    rcpp_result_gen = Rcpp::wrap(ppm_to_pwmC(position, bkg, pseudocount, nsites));
    return rcpp_result_gen;
END_RCPP
}
// pwm_to_ppmC
NumericVector pwm_to_ppmC(NumericVector position, NumericVector bkg);
RcppExport SEXP _universalmotif_pwm_to_ppmC(SEXP positionSEXP, SEXP bkgSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< NumericVector >::type position(positionSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type bkg(bkgSEXP);
    rcpp_result_gen = Rcpp::wrap(pwm_to_ppmC(position, bkg));
    return rcpp_result_gen;
END_RCPP
}
// ppm_to_icmC
NumericVector ppm_to_icmC(NumericVector position, NumericVector bkg, bool relative_entropy);
RcppExport SEXP _universalmotif_ppm_to_icmC(SEXP positionSEXP, SEXP bkgSEXP, SEXP relative_entropySEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< NumericVector >::type position(positionSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type bkg(bkgSEXP);
    Rcpp::traits::input_parameter< bool >::type relative_entropy(relative_entropySEXP);
    rcpp_result_gen = Rcpp::wrap(ppm_to_icmC(position, bkg, relative_entropy));
    return rcpp_result_gen;
END_RCPP
}
// position_icscoreC
double position_icscoreC(NumericVector position, NumericVector bkg, String type, double pseudocount, double nsites, bool relative_entropy);
RcppExport SEXP _universalmotif_position_icscoreC(SEXP positionSEXP, SEXP bkgSEXP, SEXP typeSEXP, SEXP pseudocountSEXP, SEXP nsitesSEXP, SEXP relative_entropySEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< NumericVector >::type position(positionSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type bkg(bkgSEXP);
    Rcpp::traits::input_parameter< String >::type type(typeSEXP);
    Rcpp::traits::input_parameter< double >::type pseudocount(pseudocountSEXP);
    Rcpp::traits::input_parameter< double >::type nsites(nsitesSEXP);
    Rcpp::traits::input_parameter< bool >::type relative_entropy(relative_entropySEXP);
    rcpp_result_gen = Rcpp::wrap(position_icscoreC(position, bkg, type, pseudocount, nsites, relative_entropy));
    return rcpp_result_gen;
END_RCPP
}
// icm_to_ppmC
NumericVector icm_to_ppmC(NumericVector position);
RcppExport SEXP _universalmotif_icm_to_ppmC(SEXP positionSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< NumericVector >::type position(positionSEXP);
    rcpp_result_gen = Rcpp::wrap(icm_to_ppmC(position));
    return rcpp_result_gen;
END_RCPP
}
// get_consensusC
String get_consensusC(NumericVector pos, String alphabet, String type, double pseudocount);
RcppExport SEXP _universalmotif_get_consensusC(SEXP posSEXP, SEXP alphabetSEXP, SEXP typeSEXP, SEXP pseudocountSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< NumericVector >::type pos(posSEXP);
    Rcpp::traits::input_parameter< String >::type alphabet(alphabetSEXP);
    Rcpp::traits::input_parameter< String >::type type(typeSEXP);
    Rcpp::traits::input_parameter< double >::type pseudocount(pseudocountSEXP);
    rcpp_result_gen = Rcpp::wrap(get_consensusC(pos, alphabet, type, pseudocount));
    return rcpp_result_gen;
END_RCPP
}
// consensus_to_ppmC
NumericVector consensus_to_ppmC(String letter);
RcppExport SEXP _universalmotif_consensus_to_ppmC(SEXP letterSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< String >::type letter(letterSEXP);
    rcpp_result_gen = Rcpp::wrap(consensus_to_ppmC(letter));
    return rcpp_result_gen;
END_RCPP
}
// consensus_to_ppmAAC
NumericVector consensus_to_ppmAAC(String letter);
RcppExport SEXP _universalmotif_consensus_to_ppmAAC(SEXP letterSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< String >::type letter(letterSEXP);
    rcpp_result_gen = Rcpp::wrap(consensus_to_ppmAAC(letter));
    return rcpp_result_gen;
END_RCPP
}
// get_consensusAAC
String get_consensusAAC(NumericVector position, String type, double pseudocount);
RcppExport SEXP _universalmotif_get_consensusAAC(SEXP positionSEXP, SEXP typeSEXP, SEXP pseudocountSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< NumericVector >::type position(positionSEXP);
    Rcpp::traits::input_parameter< String >::type type(typeSEXP);
    Rcpp::traits::input_parameter< double >::type pseudocount(pseudocountSEXP);
    rcpp_result_gen = Rcpp::wrap(get_consensusAAC(position, type, pseudocount));
    return rcpp_result_gen;
END_RCPP
}
// clean_up_check
StringVector clean_up_check(StringVector fails);
RcppExport SEXP _universalmotif_clean_up_check(SEXP failsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< StringVector >::type fails(failsSEXP);
    rcpp_result_gen = Rcpp::wrap(clean_up_check(fails));
    return rcpp_result_gen;
END_RCPP
}
// check_fun_params
StringVector check_fun_params(List param_args, IntegerVector param_len, LogicalVector param_null, int expected_type);
RcppExport SEXP _universalmotif_check_fun_params(SEXP param_argsSEXP, SEXP param_lenSEXP, SEXP param_nullSEXP, SEXP expected_typeSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< List >::type param_args(param_argsSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type param_len(param_lenSEXP);
    Rcpp::traits::input_parameter< LogicalVector >::type param_null(param_nullSEXP);
    Rcpp::traits::input_parameter< int >::type expected_type(expected_typeSEXP);
    rcpp_result_gen = Rcpp::wrap(check_fun_params(param_args, param_len, param_null, expected_type));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_universalmotif_single_to_k", (DL_FUNC) &_universalmotif_single_to_k, 2},
    {"_universalmotif_peakfinder_cpp", (DL_FUNC) &_universalmotif_peakfinder_cpp, 2},
    {"_universalmotif_linbin_cpp", (DL_FUNC) &_universalmotif_linbin_cpp, 2},
    {"_universalmotif_calc_scores_cpp", (DL_FUNC) &_universalmotif_calc_scores_cpp, 2},
    {"_universalmotif_kmer_mat_to_probs_k1_cpp", (DL_FUNC) &_universalmotif_kmer_mat_to_probs_k1_cpp, 3},
    {"_universalmotif_init_paths_cpp", (DL_FUNC) &_universalmotif_init_paths_cpp, 3},
    {"_universalmotif_list_to_matrix", (DL_FUNC) &_universalmotif_list_to_matrix, 1},
    {"_universalmotif_calc_next_path_cpp", (DL_FUNC) &_universalmotif_calc_next_path_cpp, 4},
    {"_universalmotif_expand_scores", (DL_FUNC) &_universalmotif_expand_scores, 1},
    {"_universalmotif_paths_alph_unsort", (DL_FUNC) &_universalmotif_paths_alph_unsort, 2},
    {"_universalmotif_paths_to_alph", (DL_FUNC) &_universalmotif_paths_to_alph, 2},
    {"_universalmotif_add_cols", (DL_FUNC) &_universalmotif_add_cols, 5},
    {"_universalmotif_motif_simil_internal", (DL_FUNC) &_universalmotif_motif_simil_internal, 9},
    {"_universalmotif_list_to_matrix_simil", (DL_FUNC) &_universalmotif_list_to_matrix_simil, 3},
    {"_universalmotif_merge_add_cols", (DL_FUNC) &_universalmotif_merge_add_cols, 1},
    {"_universalmotif_merge_motifs_get_offset", (DL_FUNC) &_universalmotif_merge_motifs_get_offset, 8},
    {"_universalmotif_merge_motifs_internal", (DL_FUNC) &_universalmotif_merge_motifs_internal, 11},
    {"_universalmotif_scan_sequences_cpp", (DL_FUNC) &_universalmotif_scan_sequences_cpp, 6},
    {"_universalmotif_shuffle_markov_cpp", (DL_FUNC) &_universalmotif_shuffle_markov_cpp, 4},
    {"_universalmotif_shuffle_euler_cpp", (DL_FUNC) &_universalmotif_shuffle_euler_cpp, 4},
    {"_universalmotif_shuffle_linear_cpp", (DL_FUNC) &_universalmotif_shuffle_linear_cpp, 4},
    {"_universalmotif_shuffle_k1_cpp", (DL_FUNC) &_universalmotif_shuffle_k1_cpp, 3},
    {"_universalmotif_count_klets_cpp", (DL_FUNC) &_universalmotif_count_klets_cpp, 3},
    {"_universalmotif_get_klets_cpp", (DL_FUNC) &_universalmotif_get_klets_cpp, 2},
    {"_universalmotif_shuffle_markov_loop", (DL_FUNC) &_universalmotif_shuffle_markov_loop, 7},
    {"_universalmotif_trim_motif_internal", (DL_FUNC) &_universalmotif_trim_motif_internal, 3},
    {"_universalmotif_universalmotif_cpp", (DL_FUNC) &_universalmotif_universalmotif_cpp, 18},
    {"_universalmotif_check_bkg_names", (DL_FUNC) &_universalmotif_check_bkg_names, 2},
    {"_universalmotif_validObject_universalmotif", (DL_FUNC) &_universalmotif_validObject_universalmotif, 2},
    {"_universalmotif_summarise_motifs_cpp", (DL_FUNC) &_universalmotif_summarise_motifs_cpp, 1},
    {"_universalmotif_universalmotif_to_list", (DL_FUNC) &_universalmotif_universalmotif_to_list, 1},
    {"_universalmotif_sort_unique_cpp", (DL_FUNC) &_universalmotif_sort_unique_cpp, 1},
    {"_universalmotif_table_cpp", (DL_FUNC) &_universalmotif_table_cpp, 1},
    {"_universalmotif_collapse_rows_mat", (DL_FUNC) &_universalmotif_collapse_rows_mat, 1},
    {"_universalmotif_collapse_cols_mat", (DL_FUNC) &_universalmotif_collapse_cols_mat, 1},
    {"_universalmotif_collapse_rows_df", (DL_FUNC) &_universalmotif_collapse_rows_df, 1},
    {"_universalmotif_collapse_cpp", (DL_FUNC) &_universalmotif_collapse_cpp, 1},
    {"_universalmotif_print_pb", (DL_FUNC) &_universalmotif_print_pb, 1},
    {"_universalmotif_update_pb", (DL_FUNC) &_universalmotif_update_pb, 2},
    {"_universalmotif_all_checks_collapse", (DL_FUNC) &_universalmotif_all_checks_collapse, 1},
    {"_universalmotif_pcm_to_ppmC", (DL_FUNC) &_universalmotif_pcm_to_ppmC, 2},
    {"_universalmotif_ppm_to_pcmC", (DL_FUNC) &_universalmotif_ppm_to_pcmC, 2},
    {"_universalmotif_ppm_to_pwmC", (DL_FUNC) &_universalmotif_ppm_to_pwmC, 4},
    {"_universalmotif_pwm_to_ppmC", (DL_FUNC) &_universalmotif_pwm_to_ppmC, 2},
    {"_universalmotif_ppm_to_icmC", (DL_FUNC) &_universalmotif_ppm_to_icmC, 3},
    {"_universalmotif_position_icscoreC", (DL_FUNC) &_universalmotif_position_icscoreC, 6},
    {"_universalmotif_icm_to_ppmC", (DL_FUNC) &_universalmotif_icm_to_ppmC, 1},
    {"_universalmotif_get_consensusC", (DL_FUNC) &_universalmotif_get_consensusC, 4},
    {"_universalmotif_consensus_to_ppmC", (DL_FUNC) &_universalmotif_consensus_to_ppmC, 1},
    {"_universalmotif_consensus_to_ppmAAC", (DL_FUNC) &_universalmotif_consensus_to_ppmAAC, 1},
    {"_universalmotif_get_consensusAAC", (DL_FUNC) &_universalmotif_get_consensusAAC, 3},
    {"_universalmotif_clean_up_check", (DL_FUNC) &_universalmotif_clean_up_check, 1},
    {"_universalmotif_check_fun_params", (DL_FUNC) &_universalmotif_check_fun_params, 4},
    {NULL, NULL, 0}
};

RcppExport void R_init_universalmotif(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
