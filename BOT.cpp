#include "BOT.h"
#include <iostream>
#include "CoreMinimal.h"

using namespace std;


ABOT::ABOT()
{
 	
	PrimaryActorTick.bCanEverTick = true;

}


void ABOT::BeginPlay()
{
	Super::BeginPlay();

	MyBOT* mybot = MyBOT::getinstance();
	mybot->move();
	mybot->MoveEnd();
	
}


void ABOT::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

