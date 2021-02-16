#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
  MPI_Comm even_comm_id,odd_comm_id;
  MPI_Group even_group_id,odd_group_id,world_group_id;
  int even_id,even_id_sum,even_p,id,odd_id,odd_id_sum,odd_p;

  MPI_Init(NULL, NULL);

  MPI_Comm_rank(MPI_COMM_WORLD, &id);
  MPI_Comm_group(MPI_COMM_WORLD, &world_group_id);
  
  int even_rank[2] = {0,2};
  MPI_Group_incl(world_group_id, 2, even_rank, &even_group_id);
  MPI_Comm_create(MPI_COMM_WORLD, even_group_id, &even_comm_id);
  
  int odd_rank[2] = {1,3};
  MPI_Group_incl(world_group_id, 2, odd_rank, &odd_group_id);
  MPI_Comm_create(MPI_COMM_WORLD, odd_group_id, &odd_comm_id);
  if (id % 2 == 0)
  {
    MPI_Comm_rank(even_comm_id, &even_id);
    odd_id = -1;
  }
  else
  {
    MPI_Comm_rank(odd_comm_id, &odd_id);
    even_id = -1;
  }
  if (even_id != -1)
  {
    MPI_Reduce(&id, &even_id_sum, 1, MPI_INT, MPI_SUM, 0, even_comm_id);
  }
  if (even_id == 0)
  {
    printf("  Sum of global ID's in even communicator  = %d\n", even_id_sum);
  }
  if (odd_id != -1)
  {
    MPI_Reduce(&id, &odd_id_sum, 1, MPI_INT, MPI_SUM, 0, odd_comm_id);
  }
  if (odd_id == 0)
  {
    printf("  Sum of global ID's in odd communicator   = %d\n", odd_id_sum);
  }
  MPI_Finalize();
  return 0;
}

