// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTBB_RegisterLastKnownLoc.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTBB_RegisterLastKnownLoc::UBTTBB_RegisterLastKnownLoc()
{
	NodeName = "Register Player Last Known Loc";
}


EBTNodeResult::Type UBTTBB_RegisterLastKnownLoc::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);


	OwnerComp.GetBlackboardComponent()->SetValueAsVector( GetSelectedBlackboardKey(), OwnerComp.GetBlackboardComponent()->GetValueAsVector("PlayerLocation"));

	return EBTNodeResult::Succeeded;
}