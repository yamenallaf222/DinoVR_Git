// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTBB_CheckAIType.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "DinoVR/DinosaurCharacter.h"
#include "DinoVR/SoldierCharacter.h"
#include "AIController.h"

#define Dinosaur 0

#define Soldier 1

UBTTBB_CheckAIType::UBTTBB_CheckAIType()
{
	NodeName = "CheckAIType";
}


EBTNodeResult::Type UBTTBB_CheckAIType::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	AAIController* AIController = OwnerComp.GetAIOwner();

	UBlackboardComponent* Blackboard = OwnerComp.GetBlackboardComponent();

	if (!ensure(Blackboard != nullptr)) return EBTNodeResult::Failed;
	if (!ensure(AIController != nullptr)) return EBTNodeResult::Failed;

	if(Cast<ADinosaurCharacter>(AIController->GetPawn()))
		Blackboard->SetValueAsEnum(GetSelectedBlackboardKey(), Dinosaur);

	if(Cast<ASoldierCharacter>(AIController->GetPawn()))
		Blackboard->SetValueAsEnum(GetSelectedBlackboardKey(), Soldier);


	return EBTNodeResult::Succeeded;

}
