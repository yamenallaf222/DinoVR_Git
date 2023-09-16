// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTBB_CheckAIType.generated.h"

/**
 * 
 */



UCLASS()
class DINOVR_API UBTTBB_CheckAIType : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);
public:
	UBTTBB_CheckAIType();


	
};

