// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MHUD.generated.h"

/**
 * 
 */
UCLASS()
class MOMA_C_API AMHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	virtual void DrawHUD() override;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class UUserWidget> PossessionWidgetClass;

	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UUserWidget* PossessionWidget;

public:
	UFUNCTION(BlueprintNativeEvent)
	void UpdatePossessionUI();

};
