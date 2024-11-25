/**
*  _____                                                                                                _____
* ( ___ )                                                                                              ( ___ )
*  |   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|   |
*  |   | ############################################################################################## |   |
*  |   | ##████████╗██████╗##█████╗#███╗###██╗███████╗███████╗#██████╗#██████╗#███╗###███╗###██╗##██╗## |   |
*  |   | ##╚══██╔══╝██╔══██╗██╔══██╗████╗##██║██╔════╝██╔════╝██╔═══██╗██╔══██╗████╗#████║###██║##██║## |   |
*  |   | #####██║###██████╔╝███████║██╔██╗#██║███████╗█████╗##██║###██║██████╔╝██╔████╔██║###███████║## |   |
*  |   | #####██║###██╔══██╗██╔══██║██║╚██╗██║╚════██║██╔══╝##██║###██║██╔══██╗██║╚██╔╝██║###██╔══██║## |   |
*  |   | #####██║###██║##██║██║##██║██║#╚████║███████║██║#####╚██████╔╝██║##██║██║#╚═╝#██║██╗██║##██║## |   |
*  |   | #####╚═╝###╚═╝##╚═╝╚═╝##╚═╝╚═╝##╚═══╝╚══════╝╚═╝######╚═════╝#╚═╝##╚═╝╚═╝#####╚═╝╚═╝╚═╝##╚═╝## |   |
*  |   | ############################################################################################## |   |
*  |___|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|___|
* (_____)                                                                                              (_____)
* 
* 
* SUMMARY:
*
* KNOWN ISSUES:
*
* STRUCTURES:
*	- Transform
*		# Definition:
*			Used with object's position representation
*		# Knowwn issues:
*			NoN
*		# Note
*			Propably most complicated and optimized part of the whole project.
* 
* 
* METHODS:
*	- Transform : CreateTransform (int, int)
*		# Definition:
*			## Summary:
*				Constructor method to create Transform and set default position
*			## Parameters:
*				- int WorldX  : Entity's world position's X
*				- int WorldY : Entity's world position's Y
*			## Known Issues:
*				- NoN
*			## Note: 
*				
*
* USED REFRENCES:
*	- https://www.youtube.com/watch?v=W_Knvo9NuJY&t=11s - Reseearch on floats
*	- https://www.youtube.com/watch?v=dQhj5RGtag0 - Some more Research on floats
*	- https://crypto.stackexchange.com/questions/19470/how-is-xor-used-for-encryption - Gave bad ideas
*	- 
* 
* 
*/

#ifndef _transform_h_

#pragma once
#pragma pack(1)

//!NOTE: Defines


//!NOTE: Includes
#include <stdint.h>

//!NOTE: Typedefs

/*
* NAME: Transform
* SUMMARY:
*	Represents object's position in world space
*/
typedef struct Transform {
	
	//First half
	
	uint_fast64_t VectorpointA : 4;
	uint_fast64_t VectorpointB : 4;
	uint_fast64_t CorrectionVectorpoint : 4;
	uint_fast64_t DistanceDecimal : 10;
	uint_fast64_t CorrectionDecimal : 10;



} Transform;

//!NOTE: Methods

#endif