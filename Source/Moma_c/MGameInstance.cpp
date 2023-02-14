// Fill out your copyright notice in the Description page of Project Settings.


#include "MGameInstance.h"
#include "MHUD.h"

void UMGameInstance::BuyCity(FST_City CurCity)
{
	if (Possessions >= CurCity.Price)
	{
		Possessions -= CurCity.Price;

		if(MHUD == nullptr)
			MHUD = Cast<AMHUD>(GetWorld()->GetFirstPlayerController()->GetHUD());

		if (MHUD)
		{
			MHUD->UpdatePossessionUI();
		}
	}
}
