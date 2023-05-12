#include "main.h"
/**
 * err - pritns error msg & exit with the corresponding error code
 * @file: file name causing the error
 * @err: error number
 */
void err(char *file, int err)
{
	if (err == 1)
	{
		dprintf(STDERR_FILENO, "readelf: Error: \'%s\': No such file\n", file);
		exit(98);
	}
	if (err == 98)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file);
		exit(98);
	}
	if (err == 127)
	{
		dprintf(STDERR_FILENO, "Error: not an ELF file\n");
		exit(98);
	}
	else
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", err);
		exit(98);
	}
}

/**
 * close_fd - close a file descriptor,
 * if it can close it exit with code 100 and print an error msg
 * @fd: file descriptor to close
 */
void close_fd(int fd)
{
	if (close(fd) == -1)
		err("", fd);
}

/**
 * print_magic - prints the magic numbers of the ELF header file.
 * @e: ELF header
 */
void print_magic(unsigned char *e)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT - 1; i++)
		printf("%02x ", e[i]);
	printf("%02x\n", e[i]);
}

/**
 * print_class - prints the class of the ELF header file.
 * @e: ELF header
 */
void print_class(unsigned char *e)
{
	printf("  %-35s", "Class:");
	if (e[EI_CLASS] > 2)
		printf("<unknown: %x>\n", e[EI_CLASS]);
	else
		printf("%s\n", e[EI_CLASS] == ELFCLASS64 ? "ELF64" :
						e[EI_CLASS] == ELFCLASS32 ? "ELF32" : "none");
}

/**
 * print_data - prints the data of the ELF header file.
 * @e: ELF header
 */
void print_data(unsigned char *e)
{

	printf("  %-35s", "Data:");
	if (e[EI_DATA] > 2)
		printf("<unknown: %x>\n", e[EI_DATA]);
	else if (e[EI_DATA] == 0)
		printf("none\n");
	else
		printf("2's complement, %s\n", e[EI_DATA] == ELFDATA2LSB ?
			"little endian" : e[EI_DATA] == ELFDATA2MSB ? "big endian" : "");
}

/**
 * print_vrs - prints the version of the ELF header file.
 * @e: ELF header
 */
void print_vrs(unsigned char *e)
{
	printf("  %-35s%d", "Version:", e[EI_VERSION]);
	printf("%s", e[EI_VERSION] == EV_CURRENT ? " (current)\n" : "\n");
}

/**
 * print_osabi - prints the OS/ABI of the ELF header file.
 * @e: ELF header
 */
void print_osabi(unsigned char *e)
{
	char *os[18] = {"System V", "HP-UX", "NetBSD", "Linux", "GNU", "",
					"Solaris", "AIX", "IRIX", "FreeBSD", "Tru64", "Novell Modesto",
					"OpenBSD", "Open VMS", "NonStop Kernel", "AROS", "Fenix OS",
					"CloudABI"};

	printf("  %-35s", "OS/ABI:");
	if (e[EI_OSABI] == ELFOSABI_ARM)
		printf("UNIX - ARM\n");
	else if (e[EI_OSABI] == ELFOSABI_STANDALONE)
		printf("UNIX - Standalone App\n");
	else if (e[EI_OSABI] <= 17)
		printf("UNIX - %s\n", os[(int)e[EI_OSABI]]);
	else
		printf("<unknown: %x>\n", e[EI_OSABI]);
}

/**
 * print_type - prints the filetype of the ELF header file.
 * @e: ELF header
 */
void print_type(unsigned char *e)
{
	int i = e[EI_DATA] == 1 ? 16 : 17;
	char *type[4] = {"REL (Relocatable", "EXEC (Executable",
					 "DYN (Shared object", "CORE (Core"};

	printf("  %-35s", "Type:");
	if (e[i] == ET_NONE)
		printf("NONE (none)\n");
	else if (e[i] > 0 && e[i] < 5)
		printf("%s file)\n", type[(int)e[i] - 1]);
	else
		printf("<unknown>: %x\n", e[i]);
}

/**
 * print_entry - prints the entry point of the ELF header file.
 * @ee: address of the entry point.
 * @ei: ELF header
 */
void print_entry(unsigned long ee, unsigned char *ei)
{
	printf("  %-35s", "Entry point address:");

	if (ei[EI_DATA] == ELFDATA2MSB)
	{
		ee = ((ee << 8) & 0xFF00FF00) | ((ee >> 8) & 0xFF00FF);
		ee = (ee << 16) | (ee >> 16);
	}
	if (ei[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)ee);
	else
		printf("%#lx\n", ee);
}

/**
 * main - prints the information contained in the ELF header of a given file
 * @ac: number of arguments
 * @av: array of arguments
 *
 * Return: 0 on success,
 * or the corresponding error code (97, 98, 99, or 100) on failure.
 */
int main(int __attribute__((unused)) ac, char *av[])
{
	Elf64_Ehdr *hdr;
	int op, re;

	op = open(av[1], O_RDONLY);
	if (op == -1)
		err(av[1], 98);

	hdr = malloc(sizeof(Elf64_Ehdr));
	if (!hdr)
	{
		close_fd(op);
		err(av[1], 98);
	}

	re = read(op, hdr, sizeof(Elf64_Ehdr));
	if (re == -1)
	{
		free(hdr);
		close_fd(op);
		err(av[1], 98);
	}

	if (hdr->e_ident[0] != 127 || hdr->e_ident[1] != 'E' ||
		hdr->e_ident[2] != 'L' || hdr->e_ident[3] != 'F')
		err("", 127);

	printf("ELF Header:\n");
	print_magic(hdr->e_ident);
	print_class(hdr->e_ident);
	print_data(hdr->e_ident);
	print_vrs(hdr->e_ident);
	print_osabi(hdr->e_ident);
	printf("  %-35s%d\n", "ABI Version:", hdr->e_ident[EI_ABIVERSION]);
	print_type(hdr->e_ident);
	print_entry(hdr->e_entry, hdr->e_ident);

	free(hdr);
	close_fd(op);
	return (0);
}
