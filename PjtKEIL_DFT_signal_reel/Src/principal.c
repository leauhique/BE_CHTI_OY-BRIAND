

#include "DriverJeuLaser.h"
extern int DFT_ModuleAuCarre( short int * Signal64ech, char k);
extern short int LeSignal[];
int X[64];

short int dma_buf[64];
void callback_syst(){
	Start_DMA1(64);
	Wait_On_End_Of_DMA1();
	Stop_DMA1; 
	for(int k=0; k<64;k++){
		X[k] = DFT_ModuleAuCarre(dma_buf,k);
	}
}

int k[6]={17,18,19,20,23,24};
int score[6]={0,0,0,0,0,0};
int j=0;
void jeu(){
	
	Start_DMA1(64);
	Wait_On_End_Of_DMA1();
	Stop_DMA1; 
	j = (j + 1)%20;
	if(j==1){
		for(int i = 0;i<6;i++){
		X[i] = DFT_ModuleAuCarre(dma_buf,k[i]);
		if(X[i]> 10){
			score[i]++;
		}
	}
	}
	

}


int main(void)
{

	
// ===========================================================================
// ============= INIT PERIPH (faites qu'une seule fois)  =====================
// ===========================================================================

// Après exécution : le coeur CPU est clocké à 72MHz ainsi que tous les timers
CLOCK_Configure();


//configuration Systick//
Systick_Period_ff( 360000 );

Systick_Prio_IT( 2, callback_syst );	
SysTick_On ;
	
SysTick_Enable_IT ;
////
	
//configuration ADC1//
Init_TimingADC_ActiveADC_ff( ADC1, 72 )	;
Single_Channel_ADC( ADC1, 2 );
Init_Conversion_On_Trig_Timer_ff( ADC1, TIM2_CC2, 225 );
Init_ADC1_DMA1( 0, dma_buf );
	/////
	

//============================================================================	
	
	
while	(1)
	{
		
		
		
}

}

