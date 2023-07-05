// cleans the word.. separates good words by ' '
// puts in it parse_string[]
void parse_read(u8 *si)
{
	u8 temp1;
	u8 *temp3;

	temp3 = parse_string;
loc19ad:
	temp1 = *si;
loc19b9:
	if (temp1 == 0) goto loc1a4c;
	if ( (strchr(char_separators, temp1) == 0) && 
		(strchr(char_illegal, temp1) == 0) )
		goto loc19f1;
	si++;
	temp1 = *si;
	goto loc19b9;
	
loc19f1:
	if ( temp1 == 0) goto loc1a4c;
		
loc19f7:
	if ( (temp1 == 0) || (strchr(char_separators, temp1) != 0) )
	{
		if ( temp1 == 0) goto loc1a4c;
		*(temp3++) = 0x20;	// space
		goto loc19ad;
	}
	if ( strchr(char_illegal, temp1) == 0)
		*(temp3++) = temp1;
	
	si++;
	temp1 = *si;
	goto loc19f7;

	
loc1a4c:
	if ( (temp3 > parse_string) && (*(temp3-1) == 0x20) )
		temp3--;
	*temp3 = 0;
}


{
	u8 *temp3;

	temp3 = parse_string;	

	while (*si)
	{
		// skip excess separators at start and inbetween words
		if ( (strchr(char_separators, *si) != 0) ||
			(strchr(char_illegal, *si) != 0) )
		{
			si++;
		}
		else
		{
			assert(*si);
			do
			{
				if (strchr(char_separators, *si) != 0)
				{
					*(temp3++) = 0x20;	// space
					break;
				}

				if (strchr(char_illegal, *si) == 0)
					*(temp3++) = *si;
				si++;
			} while (*si != 0);
		}
	}
	
	if ( (temp3 > parse_string) && (*(temp3-1) == 0x20) )
		temp3--;
	*temp3 = 0;
}

