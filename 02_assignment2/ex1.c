//a, chuyen vong for thanh while
int factorial(int n) {
	int i, ret = 1;
	i = 2;
	while (i<=n) {
		ret *= i;
		i++;
	}
	return ret;
}

//b, chuyen vong do-while thanh while
int sample_geometric_rv (double p) {
	double q;
	int n = 0;
	q = rand_double();
	n++;
	while (q >= p){
		q = rand_double();
		n++;
	}
	return n;
}
