// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_Attack.h"
#include "AIController.h"
#include "DinoVR/SoldierCharacter.h"
#include "DinoVR/DinosaurCharacter.h"

UBTT_Attack::UBTT_Attack()
{
	NodeName = "Attack";
}


EBTNodeResult::Type UBTT_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	AAIController* AIController = OwnerComp.GetAIOwner();


	if (!ensure(AIController != nullptr))return EBTNodeResult::Failed;


	ADinoVRCharacter* Character = Cast<ASoldierCharacter>(AIController->GetCharacter());

	if (Character)
	{
		Character->Attack();

		return EBTNodeResult::Succeeded;
	}

	Character = Cast<ADinosaurCharacter>(AIController->GetCharacter());


	if (!ensure(Character!= nullptr))return EBTNodeResult::Failed;
	
	Character->Attack();



	return EBTNodeResult::Succeeded;
	
}
