template <typename T, int N>
Point<T,N>::Point(){
	for(int i=0; i<N; i++){
		v[i] = T(0);
	}
}

template <typename T, int N>
Point<T,N>::Point (const Point<T,N>& p){
	for(int i=0; i<N; i++){
		v[i] = p.v[i];
	}
}

template <typename T, int N>
template <typename S> 
void Point<T,N>::add(const Point<S,N>& s){
	for(int i=0; i<N; i++){
		v[i] += s[i];
	}
}

template <typename T, int N>
T Point<T,N>::operator[] (int index) const{
	//cout<< "[]const" <<endl;
	return v[index];
}


template <typename T, int N>
T& Point<T,N>::operator[] (int index) {
	cout<< "[]ref" <<endl;
	return v[index];
}


template <typename T, int N>
std::ostream& operator<< (std::ostream& flot, const Point<T,N>& s){
	flot<<"("<<s[0];
	for(int i=1;i<N;i++){
		flot<<", "<<s[i];
	}
	flot<<")";
	return flot;
}
