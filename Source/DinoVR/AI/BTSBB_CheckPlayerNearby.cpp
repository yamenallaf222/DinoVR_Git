// Fill out your copyright notice in the Description page of Project Settings.


#include "BTSBB_CheckPlayerNearby.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "Perception/AIPerceptionComponent.h"

UBTSBB_CheckPlayerNearby::UBTSBB_CheckPlayerNearby()
{
	NodeName = "IsPlayerInLineOfSight";
}



void UBTSBB_CheckPlayerNearby::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	FName BlackboardKeyName = GetSelectedBlackboardKey();

	UBlackboardComponent* DesiredBlackboard = OwnerComp.GetBlackboardComponent();
	if (DesiredBlackboard)
	{
		DesiredBlackboard->SetValueAsBool(BlackboardKeyName, IsPlayerNearby(OwnerComp));
	}


}




bool UBTSBB_CheckPlayerNearby::IsPlayerNearby(UBehaviorTreeComponent& OwnerComp)
{
	APawn* CurrentAIPawn = OwnerComp.GetAIOwner()->GetPawn();
	bool bPlayerNearby = false;
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0);
	if (PlayerPawn && CurrentAIPawn)
	{
		bPlayerNearby = OwnerComp.GetAIOwner()->LineOfSightTo(PlayerPawn);
		
	}

	return bPlayerNearby;

}