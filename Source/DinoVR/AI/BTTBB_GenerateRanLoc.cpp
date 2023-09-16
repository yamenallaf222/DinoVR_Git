// Fill out your copyright notice in the Description page of Project Settings.


// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTBB_GenerateRanLoc.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "NavigationSystem.h"


UBTTBB_GenerateRanLoc::UBTTBB_GenerateRanLoc()
{
	NodeName = "Generate Random Location";
}


EBTNodeResult::Type UBTTBB_GenerateRanLoc::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	FVector OwningAIPawnLoc = OwnerComp.GetAIOwner()->GetPawn()->GetActorLocation();


	UNavigationSystemV1* NavigationSystem = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());
	TOptional<FVector> FinalRanLocationAround;

	if (NavigationSystem)
	{
		FinalRanLocationAround = NavigationSystem->GetRandomPointInNavigableRadius(this, OwningAIPawnLoc, SearchRadius);

	}

	if (FinalRanLocationAround.IsSet())
	{
		UE_LOG(LogTemp, Warning, TEXT("NotFinalRanLocationAroundAI generated with value of %s"), *FinalRanLocationAround.GetValue().ToString());
		OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), FinalRanLocationAround.GetValue());
	}
	else
	{
		return EBTNodeResult::Failed;
	}


	return EBTNodeResult::Succeeded;
}