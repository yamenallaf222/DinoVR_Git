// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_CircleAroundPlayer.h"
#include "AIController.h"
#include "NavigationSystem.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTT_CircleAroundPlayer::UBTT_CircleAroundPlayer()
{
	NodeName = "SetCircleAroundPoint";
	
	
}



EBTNodeResult::Type UBTT_CircleAroundPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (!ensure(PlayerPawn != nullptr)) return EBTNodeResult::Failed;


	AAIController* AIController = OwnerComp.GetAIOwner();
	
	if (!ensure(AIController != nullptr)) return EBTNodeResult::Failed;

	UNavigationSystemV1* NavigationSystem = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());

	if (!ensure(NavigationSystem != nullptr)) return EBTNodeResult::Failed;

	FVector PointInOrbitOfPlayer = NavigationSystem->GetRandomPointInNavigableRadius(GetWorld(), PlayerPawn->GetActorLocation(), 150.f);
	
	FVector Direction = PointInOrbitOfPlayer - PlayerPawn->GetActorLocation();

	Direction.Normalize();

	PointInOrbitOfPlayer = PointInOrbitOfPlayer + Direction * 200.f;

	PointInOrbitOfPlayer = NavigationSystem->ProjectPointToNavigation(GetWorld(), PointInOrbitOfPlayer);

	DrawDebugPoint(GetWorld(),PointInOrbitOfPlayer , 20.f, FColor::Blue, 0 , 3.f);

	OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), PointInOrbitOfPlayer);



	return EBTNodeResult::Succeeded;
}