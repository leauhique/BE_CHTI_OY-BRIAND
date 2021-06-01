

#include "DriverJeuLaser.h"
#include "GestionSon.h"


int main(void)
{

// ===========================================================================
// ============= INIT PERIPH (faites qu'une seule fois)  =====================
// ===========================================================================

// Apr�s ex�cution : le coeur CPU est clock� � 72MHz ainsi que tous les timers
 CLOCK_Configure();

// configuration du Timer 4 en d�bordement 100ms
	
//** Placez votre code l� ** // 
Active_IT_Debordement_Timer( TIM4, 2, CallbackSon );

	
	
// Activation des interruptions issues du Timer 4
// Association de la fonction � ex�cuter lors de l'interruption : timer_callback
// cette fonction (si �crite en ASM) doit �tre conforme � l'AAPCS
	
//** Placez votre code l� ** // 	
Timer_1234_Init_ff( TIM4,  6551); //91 ms


PWM_Init_ff( TIM3, 3, 720);	


// configuration de PortB.1 (PB1) en sortie push-pull
GPIO_Configure(GPIOB, 1, OUTPUT, OUTPUT_PPULL);
GPIO_Configure(GPIOB, 0, OUTPUT, ALT_PPULL);	
	
	
void PWM_Set_Value_TIM3_Ch3( unsigned short int Thaut_ticks);
//============================================================================	
	
	
while	(1)
	{
		for(int i; i<10;i++){
		StartSon();
		}
	}
}

