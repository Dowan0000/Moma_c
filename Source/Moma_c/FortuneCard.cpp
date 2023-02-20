// Fill out your copyright notice in the Description page of Project Settings.

#include "FortuneCard.h"
#include "MGameInstance.h"
#include "Math/UnrealMathUtility.h"


// Sets default values
AFortuneCard::AFortuneCard()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AFortuneCard::BeginPlay()
{
	Super::BeginPlay();

	UMGameInstance *gameInstance = Cast<UMGameInstance>(GetGameInstance());
	int32 RandomInt = FMath::RandRange(1, 14);
	CsvData = gameInstance->GetFortuneRowData(RandomInt);

	if (CsvData)
	{
		NewData = CsvData->Card;

		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Card : %s"), *NewData));

		NewData = CsvData->Effect;

		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("효과 : %s"), *NewData));
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Failed")));
	}
}

// Called every frame
void AFortuneCard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
