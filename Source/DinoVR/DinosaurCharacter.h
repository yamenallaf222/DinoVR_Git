// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DinoVRCharacter.h"
#include "DinosaurCharacter.generated.h"

/**
 * 
 */
UCLASS()
class DINOVR_API ADinosaurCharacter : public ADinoVRCharacter
{
	GENERATED_BODY()

private:

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "True"))
	TSubclassOf<class AMeleeHitBox> MeleeHitBox;


public:

	void Attack()override;


	
};
