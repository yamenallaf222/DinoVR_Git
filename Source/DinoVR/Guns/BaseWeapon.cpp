// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseWeapon.h"
#include "DinoVR/DinoVRCharacter.h"

// Sets default values
ABaseWeapon::ABaseWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	SetRootComponent(Root);


}

// Called when the game starts or when spawned
void ABaseWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


AController* ABaseWeapon::GetOwnerController()
{
	APawn* OwnerPawn = Cast<APawn>(GetOwner());

	if (!ensure(OwnerPawn != nullptr))return nullptr;

	return OwnerPawn->GetController();
}


bool ABaseWeapon::GunTrace(FHitResult& BulletHitResult)
{

	FVector CameraLocation = FVector::ZeroVector;
	FRotator CameraRoation = FRotator::ZeroRotator;


	AController* OwnerController = GetOwnerController();

	if (!ensure(OwnerController != nullptr) )return false;

	OwnerController->GetPlayerViewPoint(CameraLocation, CameraRoation);

	FVector Start = CameraLocation;
	
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();

	if (!ensure(OwnerController != nullptr))return false;

	APawn* PlayerPawn = PlayerController->GetPawn();
		
	if (!ensure(PlayerPawn != nullptr))return false;
	FVector PlayerLocation = PlayerPawn->GetActorLocation();


	FVector End;

	End.X = PlayerLocation.X;
	End.Y = PlayerLocation.Y + FMath::FRandRange(- 50, + 50);
	End.Z = PlayerLocation.Z + FMath::FRandRange(- 50, + 50);



	
	DrawDebugLine(GetWorld(), Start, End, FColor::Red ,1);
	FCollisionQueryParams Params;

	Params.AddIgnoredActor(this);

	Params.AddIgnoredActor(GetOwner());

	bool bSucess = GetWorld()->LineTraceSingleByChannel(BulletHitResult, Start, End, ECollisionChannel::ECC_GameTraceChannel1, Params);

	return bSucess;

}





void ABaseWeapon::PullTrigger()
{
	
	FHitResult HitResult;

	bool bSuccess = GunTrace(HitResult);
	
	if (bSuccess)
	{
		AActor* HitActor = HitResult.GetActor();
		
		if (!ensure(HitActor != nullptr))return ;

		if(Cast<ADinoVRCharacter>(HitActor))
			UE_LOG(LogTemp, Warning , TEXT("Hit That bastard called , %s") , *HitActor->GetClass()->GetName());
	}

	else
	{

		UE_LOG(LogTemp, Warning, TEXT("Mag Empty You idoit AI Soldier"));
	}

}