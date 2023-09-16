// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTT_CircleAroundPlayer.generated.h"

/**
 * 
 */
UCLASS()
class DINOVR_API UBTT_CircleAroundPlayer : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);

public:

	UBTT_CircleAroundPlayer();


};
