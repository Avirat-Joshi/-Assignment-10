#include <stdio.h>
struct DataPacket dp;
struct control_message
{
    int opcode;
    int statuscode;
};
union Packet
{
    struct control_message cm;
    char data_payload[100];
};
enum flag
{
    Control,
    DataPayload
};
struct DataPacket
{
    enum flag f;
    union Packet p;
};
void assign()
{
    if (dp.f == Control)
    {
        printf("Enter opcode: ");
        scanf("%d", &dp.p.cm.opcode);
        printf("Enter status code: ");
        scanf("%d", &dp.p.cm.statuscode);
    }
    if (dp.f == DataPayload)
    {
        fflush(stdin);
        printf("Enter string: ");
        gets(dp.p.data_payload);
    }
}
void printPacket()
{
    if (dp.f == Control)
    {
        printf("Control Message\n");
        printf("Opcode: %d\n",dp.p.cm.opcode);
        printf("Status code: %d\n",dp.p.cm.statuscode);
    }
    if (dp.f == DataPayload)
    {
        printf("Data Payload\n");
        printf("String: %s\n",dp.p.data_payload);
    }
}
int main()
{
    printf("1.Control\n2.Data\n");
    printf("Enter choice: ");
    int n;
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        dp.f = Control;
        assign(dp);
        break;
    case 2:
        dp.f = DataPayload;
        assign(dp);
        break;
    default:
        printf("Wrong choice");
        return 0;    
    }
    printf("Printing data: \n");
    printPacket();
    return 0;
}