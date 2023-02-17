// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DiceCheckArea.generated.h"

UCLASS()
class MOMA_C_API ADiceCheckArea : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADiceCheckArea();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
public:
	UFUNCTION(BlueprintCallable)
		void CheckDices();


	UPROPERTY(EditAnywhere , BlueprintReadWrite)
		TArray<AActor*> DiceArray;

	UFUNCTION(BlueprintCallable)
		void LinetraceDice(FVector StartLoc , FVector EndLoc , AActor* Dice);

	UPROPERTY(EditAnywhere , BlueprintReadWrite)
	class AMoma_cCharacter* Character;


};
