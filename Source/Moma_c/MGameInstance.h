// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "FST_City.h"
#include "FortuneCard.h"
#include "MGameInstance.generated.h"

/**
 * 
 */
struct FCsvData;
class UDataTable;

UCLASS()
class MOMA_C_API UMGameInstance : public UGameInstance
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void BuyCity(FST_City CurCity, ACharacter* Character);

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Possessions", meta = (AllowPrivateAccess = "true"))
	int32 Possessions = 100;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class AMHUD* MHUD;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class AMoma_cCharacter* MCharacter;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class AActor> Ground;

public:
	UMGameInstance();
	
	
	FCsvData* GetRowData(int32 RowName);
	
	UPROPERTY()
	UDataTable* CsvDataTable;



};
