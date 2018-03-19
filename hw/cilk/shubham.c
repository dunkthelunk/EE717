void GenG(int **A, int **B, int N, int G);
void GenNext(int **A, int **B, int N, int i, int j);


GenG(int **A, int **B, int N, int G){
	int i,j,k;
	for(k=0;k<G;k++){
		cilk for(i=0;i<N;i++){
			cilk for(j=0;j<N;j++){
				spawn GenNext(A,B,N,i,j);
			}
		}
		sync;
	}
}


void GenNext(int **A, int **B, int N, int i, int j){
	
	// NumNeb is calculated
	int row,col,NumNeb=0;
	
	for(row=i-1;row <= i+1;row++){
		for(col=j-1;col <= j+1; col++){
			if(row==i && col==j){
				//do nothing
			}
			else{
				NumNeb += A[row][col];
			}
		}
	}
	
	// Any live cell with fewer than two live neighbours dies, as if caused by under-population.
    //Any live cell with two or three live neighbours lives on to the next generation.
    //Any live cell with more than three live neighbours dies, as if by over-population.
    //Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.

	if(NumNeb < 2 ){
		B[i][j]=0;
	}
    else if(NumNeb==2){
		//do nothing
		B[i][j]=B[i][j];
	}
	else if(NumNeb==3){
		B[i][j]=1;
	}
	else if(NumNeb>3){
		B[i][j]=0;
	}
}
