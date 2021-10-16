struct items
{
    char item_name[50];
    float price;
    int quantity;
};

void welcome();
int read_price(struct items *, int n);
float calculate(struct items *, int n, float tax);
void output(struct items *, int n, float total);
void display(FILE *fp, int n);
void read(FILE *fp, char* name, int number);