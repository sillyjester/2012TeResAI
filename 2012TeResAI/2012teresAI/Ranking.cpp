//AI�̍ŏI���ʂ��o�͂���
//7/23 tao31 �V�K�ǉ�
#include "Data.h"


int colswitch(int c){
	int Cr;
	switch(c){
	case 1: Cr = GetColor(238,185,15);
		break;
	case 2:Cr = GetColor(165,165,165);
		break;
	case 3: Cr = GetColor(202,176,55);
		break;
	default: Cr = GetColor(100,100,100);
		break;
	}
	return Cr;
}

void ranking(AI_T ai[],int deth[]){
	int hoge,Cr;
	int j ;
	int space=0;
	int drawX=500;
	for(int i=0;i<AI_NUM;i++){

		ai[i].life = deth[i];
		j=i;
		//main�֐����deth[]�������Ɏ��A���������ɕ��ёւ�
		while(j>0&&deth[j-1]>deth[j]){
			hoge = deth[j-1];
			deth[j-1] = deth[j];
			deth[j] = hoge;
			j--;
		}
	}
	while(drawX>0){
		space=1;
		ClearDrawScreen();
		for(int i = 0;i<AI_NUM;i++){
			for(int k=0;k<AI_NUM;k++){
				if(ai[k].life==deth[i]){
					if(i>0 && deth[i-1]==deth[i])continue;

					Cr = colswitch(i+1);

				
					DrawFormatString(50+drawX*space,200+space*20,Cr,"%d �� %d ��",i+1,deth[i]);

					DrawString(130+drawX*space,200+space*20,ai[k].name,GetColor(255,0,0));
			
					DrawGraph(200+drawX*space,200+space*20,ai[k].Graph,TRUE);

					

					space++;
				}
			}
		}
		drawX-=10;
		WaitTimer(1000/60);
	}
}