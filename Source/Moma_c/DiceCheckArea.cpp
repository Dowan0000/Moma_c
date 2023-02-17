// Fill out your copyright notice in the Description page of Project Settings.


#include "DiceCheckArea.h"
#include "Kismet/GameplayStatics.h"
#include "Components/PrimitiveComponent.h"
#include "Moma_cCharacter.h"
#include "DrawDebugHelpers.h"

// Sets default values
ADiceCheckArea::ADiceCheckArea()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADiceCheckArea::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ADiceCheckArea::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADiceCheckArea::CheckDices()
{
	GEngine->AddOnScreenDebugMessage(-1 , 10 , FColor::Orange , TEXT("CheckDices"));

	UGameplayStatics::GetAllActorsWithTag(GetWorld() , TEXT("Dice") , DiceArray);
	GEngine->AddOnScreenDebugMessage(-1 , 10 , FColor::Black , FString::Printf(TEXT(" %d:DiceArray.Num()") , DiceArray.Num()));
	for (int i = 0; i < DiceArray.Num(); ++i)
	{
		if (i == 0)
		{
			FVector loc = DiceArray[i]->GetActorLocation();
			if (DiceArray[i])
			{
				GEngine->AddOnScreenDebugMessage(-1 , 10 , FColor::Orange , FString::Printf(TEXT(" %s:Dice1Name"), *DiceArray[i]->GetName()));
				GEngine->AddOnScreenDebugMessage(-1 , 10 , FColor::Orange , TEXT("DiceLocation1"));
				LinetraceDice(FVector(loc.X , loc.Y , loc.Z + 200) , loc , DiceArray[i]);
			}
		}
		if (i == 1)
		{
			FVector loc2 = DiceArray[i]->GetActorLocation();
			if (DiceArray[i])
			{
				GEngine->AddOnScreenDebugMessage(-1 , 10 , FColor::Orange , FString::Printf(TEXT(" %s:Dice2Name") ,*DiceArray[i]->GetName()));
				GEngine->AddOnScreenDebugMessage(-1 , 10 , FColor::Orange , TEXT("DiceLocation2"));
				LinetraceDice(FVector(loc2.X , loc2.Y , loc2.Z + 200) , loc2 , DiceArray[i]);
			}
		}
	}
}

void ADiceCheckArea::LinetraceDice(FVector StartLoc , FVector EndLoc , AActor* Dice)
{
	FHitResult Hit;
	FCollisionQueryParams params(NAME_None , false , this);
	FVector StartLocation = StartLoc;
	FVector EndLocation = EndLoc;
	GEngine->AddOnScreenDebugMessage(-1 , 10 , FColor::Yellow , TEXT(" CheckDices") );

	bool IsHit = GetWorld()->LineTraceSingleByChannel
	(Hit , StartLocation , EndLocation , ECollisionChannel::ECC_Visibility , params);
	
	DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Black, false, 10.f, 0U, 10.f);
	
	if (IsHit)
	{
		if (Dice == Hit.GetActor())
		{
			GEngine->AddOnScreenDebugMessage(-1 , 10 , FColor::Cyan , FString::Printf(TEXT(" %s:HitActor") , *Hit.GetActor()->GetName()));
			GEngine->AddOnScreenDebugMessage(-1 , 10 , FColor::Cyan , FString::Printf(TEXT(" %s:Dice") , *Dice->GetName()));
			GEngine->AddOnScreenDebugMessage(-1 , 10 , FColor::Cyan , FString::Printf(TEXT(" %s:HitActor.CompName") , *Hit.Component.Get()->GetName()));
			//GEngine->AddOnScreenDebugMessage(-1 , 10 , FColor::Cyan , FString::Printf(TEXT(" %s:Dice.CompName") , *Dice->GetName()));

			for (int j = 0; j < Hit.GetComponent()->ComponentTags.Num(); ++j)
			{

				GEngine->AddOnScreenDebugMessage(-1 , 10 , FColor::Purple , FString::Printf(TEXT(" Hit.GetComponent()->ComponentTags.Num(): %d") , Hit.GetComponent()->ComponentTags.Num()));
				GEngine->AddOnScreenDebugMessage(-1 , 10 , FColor::Purple , FString::Printf(TEXT(" %s:Tag") , *Hit.GetComponent()->ComponentTags[j].ToString()));
				GEngine->AddOnScreenDebugMessage(-1 , 10 , FColor::Black , FString::Printf(TEXT(" %d:Num") , FCString::Atoi(*Hit.GetComponent()->ComponentTags[j].ToString())));
				Character = Cast<AMoma_cCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
				if(Character)
				{
					//GEngine->AddOnScreenDebugMessage(-1 , 10 , FColor::Green , FString::Printf(TEXT(" 5767980")));
				}
				Character->DestBoard += FCString::Atoi64(*Hit.GetComponent()->ComponentTags[j].ToString());
				int Num = Character->DestBoard;
				Character->Go(Num);
				GEngine->AddOnScreenDebugMessage(-1 , 10 , FColor::Magenta , FString::Printf(TEXT(" %d:Num") , Num));

			}
		}
	}
}

