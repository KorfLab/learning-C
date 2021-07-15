// fizzbuzz.c
// not working yet

for (int i = 0; i < 100; i++)
{
  if (i % 3 == 0 or i % 5 == 0) {
    printf("fizzbuzz");
  } else if (i % 3 == 0) {
    printf("fizz");
  } else if (i % 5 == 0) {
    printf("buzz");
  } else {
    printf(i);
  }
}

/*
python
for i in range(1, 100):
  if i % 3 == 0:
    return 'fizz'
  if i % 5 == 0:
    return 'buzz'
  if i % 3 and i % 5:
    return 'fizzbuzz'
  else:
    return i
*/
