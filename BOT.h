#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BOT.generated.h"



UCLASS()
class PRO2_API ABOT : public AActor
{
	GENERATED_BODY()
	
public:	
	
	ABOT();

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

};

class MyBOT {
private:
	static MyBOT* instance;
	int x, y, eventCount = 0;
	float z, w = 0.00;

	MyBOT() : x(0), y(0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Character BOT Created at (%d, %d)"), x, y);
	}
public:
	static MyBOT* getinstance()
	{
		if (instance == nullptr)
		{
			instance = new MyBOT;
		}
		return instance;

	}

	void creatEvent()
	{
		int u = FMath::RandRange(0, 1);
		if (u == 0)
		{
			int a = FMath::RandRange(0, 2);
			switch (a)
			{
			case 0:
				UE_LOG(LogTemp, Warning, TEXT(" Event : Random Send Location!! "));
				x = x + FMath::RandRange(-5, 5);
				y = y + FMath::RandRange(-5, 5);
				eventCount++;
				UE_LOG(LogTemp, Display, TEXT(" Location is (%d, %d)"), x, y);
				break;

			case 1:
				UE_LOG(LogTemp, Warning, TEXT(" Event : Forward Jump!! "));
				x = x + 2;
				eventCount++;
				UE_LOG(LogTemp, Display, TEXT(" Location is (%d, %d)"), x, y);
				break;

			case 2:
				UE_LOG(LogTemp, Warning, TEXT(" Event : Side Jump!! "));
				y = y + 2;
				eventCount++;
				UE_LOG(LogTemp, Display, TEXT(" Location is (%d, %d)"), x, y);
				break;
			}
		}
	}

	float distance(FVector2D first, FVector2D second)
	{
		float dx = second.X - first.X;
		float dy = second.Y - first.Y;
		return FMath::Sqrt((dx * dx) + (dy * dy));
	}

	int step()
	{
		int Min = -1;
		int Max = 1;
		return FMath::RandRange(Min, Max);
	}


	void move()
	{
		TArray<FVector2D> VectorArray;
		VectorArray.Add(FVector2D(0, 0));

		for (int i = 0; i < 10; i++)
		{
			UE_LOG(LogTemp, Display, TEXT(" Character Move! : %d Step"), i + 1);
			x = x + step();
			y = y + step();
			UE_LOG(LogTemp, Warning, TEXT(" Location is (%d, %d)"), x, y);
			creatEvent();

			VectorArray.Add(FVector2D(x, y));
			if (i >= 0)
			{
				const FVector2D& Vec = VectorArray[i];
				const FVector2D& Vec2 = VectorArray[i+1];

				z = distance(Vec, Vec2);

				UE_LOG(LogTemp, Error, TEXT("Distance from step %d to step %d : %.2f"), i, i + 1, z);
			}
		}
	}

	void MoveEnd()
	{

		FVector2D ST(0, 0);
		FVector2D EN(x, y);
		w = distance(ST, EN);
		UE_LOG(LogTemp, Display, TEXT("Distance from end : %.2f  , Event All Count : %d "), w, eventCount);
	}

	~MyBOT()
	{
		delete instance;
		instance = nullptr;
	}
};

MyBOT* MyBOT::instance = nullptr;