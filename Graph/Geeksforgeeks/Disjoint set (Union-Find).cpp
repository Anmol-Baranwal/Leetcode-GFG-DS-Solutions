/*
    Problem Link: https://practice.geeksforgeeks.org/problems/disjoint-set-union-find/1
*/

/*Complete the functions below*/
int find(int A[],int X)
{
       //add code here
       if(X == A[X])    
            return X;
       return A[X]= find(A, A[X]);
}
void unionSet(int A[],int X,int Z)
{
	//add code here.
	int parentX= find(A, X);
	int parentZ= find(A, Z);
	
	if(parentX == parentZ)  return;
	else    A[parentX]= parentZ;
}