// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Dice.generated.h"

UCLASS()
class MOMA_C_API ADice : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADice();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:


	UPROPERTY(EditAnywhere , BlueprintReadWrite)
		FVector DiceLocation1 = FVector( 340.000000 ,  650.000000 ,  110.000000);

	UPROPERTY(EditAnywhere , BlueprintReadWrite)
		FVector DiceLocation2 = FVector(( 600.000000 ,  650.000000 ,  110.000000));

	UPROPERTY(EditAnywhere , BlueprintReadWrite)
		UStaticMeshComponent* Cube1;

	UPROPERTY(EditAnywhere , BlueprintReadWrite)
		UStaticMeshComponent* Cube2;

	UPROPERTY(EditAnywhere , BlueprintReadWrite)
		UStaticMeshComponent* Cube3;

	UPROPERTY(EditAnywhere , BlueprintReadWrite)
		UStaticMeshComponent* Cube4;

	UPROPERTY(EditAnywhere , BlueprintReadWrite)
		UStaticMeshComponent* Cube5;

	UPROPERTY(EditAnywhere , BlueprintReadWrite)
		UStaticMeshComponent* Cube6;

	UPROPERTY(EditAnywhere , BlueprintReadWrite)
		UBoxComponent* BoxComponent;
public:

	UFUNCTION(BlueprintCallable)
		void CheckPlane();

	UFUNCTION(BlueprintCallable)
		void LocationFix();




	FTimerHandle Handle;

	FTimerDelegate EventDelegate;

	TArray<AActor*> FoundDices2;


};
