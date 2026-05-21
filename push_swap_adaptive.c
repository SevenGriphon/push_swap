#include "push_swap.h"

int	ft_len(t_list *pile)
{
	int		taille;

	taille = 0;
	while (pile)
	{
		taille++;
		pile = pile->next;
	}
	return (taille);
}

double	adaptive(t_list *pile)
{
	t_list	*courant;
	double	erreurs;

	if (!pile || !pile->next)
		return (0.0);
	erreurs = 0;
	courant = pile;
	while (courant->next)
	{
		if ((int)(long)courant->content > (int)(long)courant->next->content)
			erreurs++;
		courant = courant->next;
	}
	return (erreurs / (ft_len(pile) - 1));
}