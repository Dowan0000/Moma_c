// Fill out your copyright notice in the Description page of Project Settings.


#include "Dice.h"
#include "Components/PrimitiveComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ADice::ADice()
{

	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	BoxComponent->SetWorldScale3D(FVector(1.25f , 1.25f , 1.25f));
	RootComponent = BoxComponent;
	static ConstructorHelpers::FObjectFinder<UStaticMesh>Cubemesh1(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh>Cubemesh2(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh>Cubemesh3(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh>Cubemesh4(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh>Cubemesh5(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh>Cubemesh6(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	Cube1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube1"));
	Cube2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube2"));
	Cube3 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube3"));
	Cube4 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube4"));
	Cube5 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube5"));
	Cube6 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube6"));

	if (Cubemesh1.Succeeded())
	{
		Cube1->SetupAttachment(BoxComponent);
		Cube1->SetStaticMesh(Cubemesh1.Object);
		Cube1->SetRelativeLocation(FVector(0 , 0 , 50));
		Cube1->SetRelativeScale3D(FVector(1 , 1 , 0.1));

	}
	if (Cubemesh2.Succeeded())
	{
		Cube2->SetupAttachment(BoxComponent);
		Cube2->SetStaticMesh(Cubemesh2.Object);
		Cube2->SetRelativeLocation(FVector(50 , 0 , 0));
		Cube2->SetRelativeRotation(FRotator(-90 , 0 , 0));
		Cube2->SetRelativeScale3D(FVector(1 , 1 , 0.1));
	}
	if (Cubemesh3.Succeeded())
	{
		Cube3->SetupAttachment(BoxComponent);
		Cube3->SetStaticMesh(Cubemesh3.Object);
		Cube3->SetRelativeLocation(FVector(0 , -50 , 0));
		Cube3->SetRelativeRotation(FRotator(0 , 0 , 90));
		Cube3->SetRelativeScale3D(FVector(1 , 1 , 0.1));
	}
	if (Cubemesh4.Succeeded())
	{
		Cube4->SetupAttachment(BoxComponent);
		Cube4->SetStaticMesh(Cubemesh4.Object);
		Cube4->SetRelativeLocation(FVector(0 , 50 , 0));
		Cube4->SetRelativeRotation(FRotator(0 , 0 , 90));
		Cube4->SetRelativeScale3D(FVector(1 , 1 , 0.1));
	}
	if (Cubemesh5.Succeeded())
	{
		Cube5->SetupAttachment(BoxComponent);
		Cube5->SetStaticMesh(Cubemesh5.Object);
		Cube5->SetRelativeLocation(FVector(-50 , 0 , 0));
		Cube5->SetRelativeRotation(FRotator(-90 , 0 , 0));
		Cube5->SetRelativeScale3D(FVector(1 , 1 , 0.1));
	}
	if (Cubemesh6.Succeeded())
	{
		Cube6->SetupAttachment(BoxComponent);
		Cube6->SetStaticMesh(Cubemesh6.Object);
		Cube6->SetRelativeLocation(FVector(0 , 0 , -50));
		Cube6->SetRelativeRotation(FRotator(0 , 0 , 0));
		Cube6->SetRelativeScale3D(FVector(1 , 1 , 0.1));

	}

	BoxComponent->SetSimulatePhysics(true);
	BoxComponent->SetCollisionProfileName(TEXT("BlockAllDynamic"));

}

// Called when the game starts or when spawned
void ADice::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp , Warning , TEXT("asd") , 10);
	EventDelegate.BindUFunction(this , "LocationFix");


	UGameplayStatics::GetAllActorsWithTag(GetWorld() , TEXT("Dice") , FoundDices2);

	//UGameplayStatics::GetAllActorsOfClassWithTag(GetWorld(), AExDice::StaticClass() , TEXT("Dice") , FoundDices2);

	int ArrayNum2 = FoundDices2.Num();
	//GEngine->AddOnScreenDebugMessage(-1 , 10 , FColor::Red , FString::Printf(TEXT(" %d:NumCount") , FoundDices2.Num()));
	//GEngine->AddOnScreenDebugMessage(-1 , 10 , FColor::Black , FString::Printf(TEXT(" %d:arrayNum") , ArrayNum2));

}

// Called every frame
void ADice::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



void ADice::ReqLocationFix_Implementation()
{
	ResLocationFix();
}

void ADice::ReqCheckPlane_Implementation()
{
	ResCheckPlane();
}

void ADice::ResCheckPlane_Implementation()
{
	FHitResult Hit;
	FCollisionQueryParams params(NAME_None , false , this);
	FVector StartLocation = GetActorLocation();
	FVector EndLocation = FVector(GetActorLocation().X , GetActorLocation().Y , GetActorLocation().Z - 10000);

	bool IsHit = GetWorld()->LineTraceSingleByChannel
	(Hit , StartLocation , EndLocation , ECollisionChannel::ECC_Visibility , params);


	if (IsHit)
	{
		UE_LOG(LogTemp , Error , TEXT("Hit"));
		//GEngine->AddOnScreenDebugMessage(-1 , 10 , FColor::Red , FString::Printf(TEXT("impact Point: %s") , Hit.ImpactPoint));

		GEngine->AddOnScreenDebugMessage(-1 , 10 , FColor::Magenta , FString::Printf(TEXT(" %s:actor") , *Hit.GetActor()->GetName()));
		BoxComponent->AddRelativeRotation(FRotator(20 , 10 , 20));
		BoxComponent->AddImpulseAtLocation(GetActorLocation() , GetActorLocation() * (Hit.GetActor()->GetActorUpVector() * 100));

		GetWorldTimerManager().SetTimer(Handle , this , &ADice::ReqLocationFix , 7.f);

	}
}

void ADice::ResLocationFix_Implementation()
{
	UE_LOG(LogTemp , Warning , TEXT("8888888888888888888"));

	TArray<AActor*> FoundDices;
	//UGameplayStatics::GetAllActorsOfClassWithTag(GetWorld(), AExDice::StaticClass() ,TEXT("Dice"), FoundDices);
	UGameplayStatics::GetAllActorsWithTag(GetWorld() , TEXT("Dice") , FoundDices);
	int ArrayNum = FoundDices.Num();
	GEngine->AddOnScreenDebugMessage(-1 , 10 , FColor::Red , FString::Printf(TEXT(" %d:NumCount") , FoundDices.Num()));
	GEngine->AddOnScreenDebugMessage(-1 , 10 , FColor::Black , FString::Printf(TEXT(" %d:ArrayNum") , ArrayNum));
	for (int i = 0; i < FoundDices.Num(); ++i)
	{
		GEngine->AddOnScreenDebugMessage(-1 , 10 , FColor::Magenta , FString::Printf(TEXT(" %d:Count") , FoundDices.Num()));

		//FoundDicesIndex
		if (i == 0)
		{
			if (FoundDices[i] == this)
			{
				FoundDices[i]->SetActorLocation(DiceLocation1);
				GWorld->GetTimerManager().ClearTimer(Handle);
				GEngine->AddOnScreenDebugMessage(-1 , 10 , FColor::Cyan , TEXT("DiceLocation1"));
			}
		}
		if (i == 1)
		{
			if (FoundDices[i] == this)
			{
				FoundDices[i]->SetActorLocation(DiceLocation2);
				GWorld->GetTimerManager().ClearTimer(Handle);
				GEngine->AddOnScreenDebugMessage(-1 , 10 , FColor::Black , TEXT("DiceLocation2"));
			}
		}
	}


}