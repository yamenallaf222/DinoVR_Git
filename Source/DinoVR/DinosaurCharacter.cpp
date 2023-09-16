// Fill out your copyright notice in the Description page of Project Settings.


#include "DinosaurCharacter.h"
#include "MeleeHitBox.h"

void ADinosaurCharacter::Attack()
{

	FTransform MeleeHitBoxTranform = GetActorTransform();

	FVector DesiredHitBoxLocation = GetActorLocation() + GetActorForwardVector() * 150;

	MeleeHitBoxTranform.SetLocation(DesiredHitBoxLocation);

	if (!ensure(MeleeHitBox != nullptr)) return;
		GetWorld()->SpawnActorAbsolute<AMeleeHitBox>(MeleeHitBox, MeleeHitBoxTranform);


}




