// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/RSP_KeyPressEvent.h"
#include "Components/Image.h"

void URSP_KeyPressEvent::SetTexture(UTexture2D* texture)
{
	RSP_KeyImage->SetBrushFromTexture(texture);
}
