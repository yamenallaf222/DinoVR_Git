// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTBB_GenerateRanLoc.generated.h"

/**
 * 
 */
UCLASS()
class DINOVR_API UBTTBB_GenerateRanLoc : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
public:

	UBTTBB_GenerateRanLoc();

private:
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)override;

	UPROPERTY(EditAnywhere)
		float SearchRadius = 300.f;
};
