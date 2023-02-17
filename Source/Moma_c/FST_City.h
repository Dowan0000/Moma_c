#pragma once

#include "Engine/DataTable.h"
#include "FST_City.generated.h"

USTRUCT(BlueprintType)
struct FST_City : public FTableRowBase
{
	GENERATED_BODY()

public:
	FST_City()
	{}

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CityInformation")
	FString CityName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CityInformation")
	int32 LandPrice;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CityInformation")
	int32 FirstPrice;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CityInformation")
	int32 SecondPrice;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CityInformation")
	int32 ThirdPrice;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CityInformation")
	int32 LandMarkPrice;



	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CityInformation")
		FString Color;



	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CityInformation")
		FString State;

};