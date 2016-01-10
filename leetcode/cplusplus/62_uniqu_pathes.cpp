int uniquePaths(int m, int n) {
        int* sum =new int;
        *sum=0;
        uniquePathsHelper(sum,m-1, n-1);
        return *sum;
}
    
void uniquePathsHelper(int* sum,int m, int n) {
    if(m==0||n==0){
        (*sum)+=1;
        return;}
    if(m>0){
        uniquePathsHelper(sum,m-1,n);
    }
    if(n>0){
        uniquePathsHelper(sum,m,n-1);
    }
}

int main(){
	cout<<uniquePaths(2,2)<<endl;
	return 0;
}
