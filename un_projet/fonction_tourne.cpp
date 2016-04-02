#include "fonction_tourne"

int find_max(int luminosite [],  int N){
	int max = 0;
	int imax = 0;
	for (int i = 0; i<N; i++){
		if(luminosite[i]>max){
			max = luminosite[i];
			imax = i;
		}
	}
	return imax;
}
void update_photodiode(int val[],photodiode * nos_capteurs,N){

	for (int i = 0; i<N; i++){
		val[i]=(*(nos_capteurs+N)).get_val();
	}
}
