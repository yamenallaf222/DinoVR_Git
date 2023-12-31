// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTBB_RegisterLastKnownLoc.generated.h"

/**
 * 
 */
UCLASS()
class DINOVR_API UBTTBB_RegisterLastKnownLoc : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

private:
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)override;

public:
	UBTTBB_RegisterLastKnownLoc();


};
