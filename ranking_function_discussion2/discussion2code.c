function findDiv(){
    list<Points> S = sampling(Q);
    list<CounterExample> cel = S;
    while(!cel.isEmpty()){
        S = union(S, cel);
        if Z3_check_consistent(S){
            f = candidateRankingFunction(S);
            list<CounterExample> cel = Z3_check_f_for_S(f, S);
            if(cel.isEmpty()){
                return f;
            }
        } else {
            list<CounterExample> cel = Z3_generate_Pairs(S, f); 
        }
    }
}

MPhRF generateRF(Program P){
	list<Term> disjunctiveTerms;
	disjunctiveTerms = extractTerms(P);
	MPhRF rf= findDivisionOrder(disjunctiveTerms);
	return rf;
}
