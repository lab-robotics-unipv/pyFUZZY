#include "MFShapes.h"

/*! INFORMATION ABOUT THE NUMBER OF THE POINTS OF INTEREST
 *			input		ms				Type of the shape (Triangular, Trapezoidal, Spyke)
 *
 *			return		int				Return the number of the points of interest
 */
int getMFPoiNum(memFuncShape ms) {
	switch (ms) {
		case SIGMOID_MF:
			//Slope and Center.
			return 2; 
			
		case DIF_SIGMOID_MF:
			//Slope and Center of first Sigmoid + Slope and Center of the second one.
			return 4;
			
		case GAUSSIAN_MF:
			//Sigma and Center.
			return 2;
			
		case TRI_MF:
			return 3;

		case TRAP_MF:
			return 4;

		case SPIKE_MF:
			return 1;

		default:
			return -1;
	}
}