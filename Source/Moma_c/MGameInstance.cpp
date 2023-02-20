// Fill out your copyright notice in the Description page of Project Settings.


#include "MGameInstance.h"
#include "MHUD.h"
#include "Moma_cCharacter.h"

void UMGameInstance::BuyCity(FST_City CurCity, ACharacter* Character)
{
	if(MCharacter == nullptr)
		MCharacter = Cast<AMoma_cCharacter>(Character);

	if (MCharacter)
	{
		if (Ground == nullptr) return;
		
		FVector Location = MCharacter->GetActorLocation() + MCharacter->GetActorRightVector() * -60.f;
		Location = Location + FVector(0.f, 0.f, -90.f);

		GetWorld()->SpawnActor<AActor>(Ground, Location, MCharacter->GetActorRotation());		

		if (Possessions >= CurCity.LandPrice)
		{
			Possessions -= CurCity.LandPrice;

			if (MHUD == nullptr)
				MHUD = Cast<AMHUD>(GetWorld()->GetFirstPlayerController()->GetHUD());

			if (MHUD)
			{
				MHUD->UpdatePossessionUI();
			}
		}
	}
	
}
UMGameInstance::UMGameInstance()
{
    FString CsvFortuneDataPath = TEXT("DataTable'/Game/Data/FortuneCard.FortuneCard'");
    static ConstructorHelpers::FObjectFinder<UDataTable> DT_FortuneCard(*CsvFortuneDataPath);
    if (DT_FortuneCard.Succeeded())
	{

		CsvFortuneDataTable = DT_FortuneCard.Object;
	
		
	}
	
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("CardDataFail"));
	}

	FString CsvBoardDataPath = TEXT("/Script/Engine.DataTable'/Game/Data/DT_City.DT_City'");
    static ConstructorHelpers::FObjectFinder<UDataTable> DT_Board(*CsvBoardDataPath);
    if (DT_Board.Succeeded())
	{

		CsvBoardDataTable = DT_Board.Object;
	
		
	}
	
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("BoardDataFail"));
	}



}


FCsvData* UMGameInstance::GetFortuneRowData(int32 RowName)
{
	return CsvFortuneDataTable->FindRow<FCsvData>(*FString::FromInt(RowName),TEXT(""));
}

FST_City* UMGameInstance::GetBoardRowData(int32 RowName)
{
	return CsvBoardDataTable->FindRow<FST_City>(*FString::FromInt(RowName),TEXT(""));
}
