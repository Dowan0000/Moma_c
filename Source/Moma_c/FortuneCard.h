// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameFramework/Actor.h"

#include "FortuneCard.generated.h"

USTRUCT(BlueprintType)
struct FCsvData : public FTableRowBase
{
    GENERATED_BODY()
    
public:
    FCsvData() : Grade(""),Card(""),Effect(""),Percentage(1) {}
    
    UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "Data")
    FString Grade;
    
    UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "Data")
    FString Card;
    
    UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "Data")
    FString Effect;
    
    UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "Data")
    int32 Percentage;
    
    
    
};


UCLASS()
class MOMA_C_API AFortuneCard : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFortuneCard();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FCsvData* CsvData;
    
   
    int32 RowData;

    
    FString NewData;
    

};
