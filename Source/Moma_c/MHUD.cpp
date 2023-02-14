// Fill out your copyright notice in the Description page of Project Settings.


#include "MHUD.h"
#include "Blueprint/UserWidget.h"

void AMHUD::DrawHUD()
{
	
}

void AMHUD::BeginPlay()
{
	Super::BeginPlay();

	if (PossessionWidgetClass)
	{
		PossessionWidget = CreateWidget<UUserWidget>(GetWorld(), PossessionWidgetClass);

		if (PossessionWidget)
		{
			PossessionWidget->AddToViewport();
		}
	}
}

void AMHUD::UpdatePossessionUI_Implementation()
{

}
