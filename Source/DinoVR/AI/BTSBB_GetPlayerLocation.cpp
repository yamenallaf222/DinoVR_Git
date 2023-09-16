// Fill out your copyright notice in the Description page of Project Settings.


#include "BTSBB_GetPlayerLocation.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTSBB_GetPlayerLocation::UBTSBB_GetPlayerLocation()
{
	NodeName = "GetPlayerLocatoin";
}


void UBTSBB_GetPlayerLocation::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);


	APawn* Pawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	if (!ensure(Pawn != nullptr))return;

	OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey() , Pawn->GetActorLocation());
}