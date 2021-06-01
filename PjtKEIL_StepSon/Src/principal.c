

#include "DriverJeuLaser.h"
#include "GestionSon.h"


int main(void)
{

// ===========================================================================
// ============= INIT PERIPH (faites qu'une seule fois)  =====================
// ===========================================================================

// Après exécution : le coeur CPU est clocké à 72MHz ainsi que tous les timers
 CLOCK_Configure();

// configuration du Timer 4 en débordement 100ms
	
//** Placez votre code là ** // 
Active_IT_Debordement_Timer( TIM4, 2, CallbackSon );

	
	
// Activation des interruptions issues du Timer 4
// Association de la fonction à exécuter lors de l'interruption : timer_callback
// cette fonction (si écrite en ASM) doit être conforme à l'AAPCS
	
//** Placez votre code là ** // 	
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

