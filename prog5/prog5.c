#include<stdio.h>
union decision{
  unsigned char flags;
  struct field
  {
    int your_choice:1;
    int your_mothers_choice:1;
    int your_fathers_choice:1;
    int socially_acceptable:1;
    int financially_viable:1;
    int do_you_aptitude:1;
    int do_you_likeit:1;
    int decision:1;
  }bits;
};

  union decision input();
  void make_decision(union decision d);
  void print_decision(union decision d);
  void print_conclusion_based_on_flags(union decision d);

int main()
{
  union decision d;
  d = input();
  make_decision(d);
  print_decision(d);
  print_conclusion_based_on_flags(d);
  return 0;


}
union decision input()
{
  union decision d;
  printf("Do you like programming? (1 for yes, 0 for no): ");
  scanf("%hhu", &d.flags);
  return d;
}
void make_decision(union decision d)
{
  d.bits.your_choice = d.flags & 1;
  d.bits.your_mothers_choice = (d.flags >> 1) & 1;
  d.bits.your_fathers_choice = (d.flags >> 2) & 1;
  d.bits.socially_acceptable = (d.flags >> 3) & 1;
  d.bits.financially_viable = (d.flags >> 4) & 1;
  d.bits.do_you_aptitude = (d.flags >> 5) & 1;
  d.bits.do_you_likeit = (d.flags >> 6) & 1;
}
void print_decision(union decision d)
{
  printf("Your choice: %d\n", d.bits.your_choice);
  printf("Your mother's choice: %d\n", d.bits.your_mothers_choice);
  printf("Your father's choice: %d\n", d.bits.your_fathers_choice);
  printf("Socially acceptable: %d\n", d.bits.socially_acceptable);
  printf("Financially viable: %d\n", d.bits.financially_viable);
  printf("Do you have aptitude: %d\n", d.bits.do_you_aptitude);
  printf("Do you like it: %d\n", d.bits.do_you_likeit);
}
void print_conclusion_based_on_flags(union decision d)
{
  if(d.bits.your_choice && d.bits.do_you_likeit && d.bits.do_you_aptitude)
  {
    printf("You should pursue programming!\n");
  }
  else if(d.bits.your_choice && (d.bits.do_you_likeit || d.bits.do_you_aptitude))
  {
    printf("Programming could be a good choice for you, but consider other factors.\n");
  }
  else
  {
    printf("Programming might not be the best choice for you based on your inputs.\n");
  }
}

