/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettimeofday.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:50:21 by davidga2          #+#    #+#             */
/*   Updated: 2023/11/25 14:28:42 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	struct timeval	exec_moment;
	time_t			exec_seconds;
	struct timeval	wait_moment;
	time_t			wait_seconds;
	//suseconds_t		microseconds;
	int				one_sec;
	int				i;
	int				wait_secs;

	if (argc != 2)
		return (printf("Error: introduce los segundos a esperar\n"), 0);
	one_sec = 1000000;
	i = 0;
	wait_secs = atoi(argv[1]);
	if (gettimeofday(&exec_moment, NULL) == -1)
		return (printf("Error\n"), 1);
	exec_seconds = exec_moment.tv_sec;
	//microseconds = right_now.tv_usec;
	printf("Segundos transcurridos desde 1970:	%li\n", exec_seconds);
	printf("Minutos transcurridos desde 1970:	%li\n", exec_seconds / 60);
	printf("Horas transcurridos desde 1970:		%li\n", exec_seconds / 60 / 60);
	printf("Días transcurridos desde 1970:		%li\n", exec_seconds / 60 / 60 / 24);
	printf("Años transcurridos desde 1970: 		%li\n", exec_seconds / 60 / 60 / 24 / 360);
	while (i < wait_secs)
	{
		printf("( ͡° ͜ʖ ͡°) 'W-A-I-T-I-N-G'\n");
		usleep(one_sec);
		i++;
	}
	if (gettimeofday(&wait_moment, NULL) == -1)
		return (printf("Error\n"), 1);
	wait_seconds = wait_moment.tv_sec;
	printf("Segundos transcurridos desde 1970:	%li\n", wait_seconds);
	printf("Minutos transcurridos desde 1970:	%li\n", wait_seconds / 60);
	printf("Horas transcurridos desde 1970:		%li\n", wait_seconds / 60 / 60);
	printf("Días transcurridos desde 1970:		%li\n", wait_seconds / 60 / 60 / 24);
	printf("Años transcurridos desde 1970: 		%li\n", wait_seconds / 60 / 60 / 24 / 360);

	//printf("\nDiferencia en segundos: %li\n", wait_moment - exec_moment);
	printf("\nDiferencia en segundos: %li\n", 
    (wait_moment.tv_sec - exec_moment.tv_sec) * 1000000 + 
    (wait_moment.tv_usec - exec_moment.tv_usec));
	//printf("Microsegundos: %i\n", microseconds);
	return (0);
}
