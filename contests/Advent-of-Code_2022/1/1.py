with open('input.txt') as f:
    maxCalorieSum = 0
    secondMaxCSum = 0
    thirdMaxCaSum = 0
    elfCalorieSum = 0
    for line in f:
        if len(line.strip()):
            elfCalorieSum += int(line.strip())
        else:
            if maxCalorieSum < elfCalorieSum:
                thirdMaxCaSum = secondMaxCSum
                secondMaxCSum = maxCalorieSum
                maxCalorieSum = elfCalorieSum
            elif secondMaxCSum < elfCalorieSum:
                thirdMaxCaSum = secondMaxCSum
                secondMaxCSum = elfCalorieSum
            elif thirdMaxCaSum < elfCalorieSum:
                thirdMaxCaSum = elfCalorieSum

            elfCalorieSum = 0

    # print(maxCalorieSum)
    print(maxCalorieSum + secondMaxCSum + thirdMaxCaSum)

