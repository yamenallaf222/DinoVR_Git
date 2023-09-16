// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTBB_RollADice.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTBB_RollADice::UBTTBB_RollADice()
{
	NodeName = "Roll A Dice";
}

EBTNodeResult::Type UBTTBB_RollADice::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);


	OwnerComp.GetBlackboardComponent()->SetValueAsBool(GetSelectedBlackboardKey(), FMath::RandBool());

	return EBTNodeResult::Succeeded;

}



