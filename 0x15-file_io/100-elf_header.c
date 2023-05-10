#include "main.h"
/**
 * err - pritns error msg & exit with the corresponding error code
 * @file: file name causing the error
 * @err: error number
 */
void err(char *file, int err)
{
	if (err == 98)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file);
		exit(98);
	}
	if (err == 99)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
		exit(99);
	}
	if (err == 127)
	{
		dprintf(STDERR_FILENO, "Error: not an ELF file\n");
		exit(98);
	}
	else
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", err);
		exit(100);
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
 * print_class - prints the class of the ELF header file.
 * @hdr: ELF header
 */
void print_class(char *hdr)
{
	printf("  %-35s", "Class:");
	printf("%s", hdr[4] == 2 ? "ELF64" : hdr[4] == 1 ? "ELF32" : "");
	if (hdr[4] > 2)
		printf("<unknown: %02hx>", hdr[4]);
	printf("\n");
}

/**
 * print_data - prints the data of the ELF header file.
 * @hdr: ELF header
 */
void print_data(char *hdr)
{
	char *data = hdr[5] == 1 ? "little endian" : hdr[5] == 2 ? "big endian"
		: NULL;
	printf("  %-35s", "Data:");
	if (data)
		printf("2's complement, %s\n", data);
	else
		printf("<unknown: %02hx>\n", hdr[5]);
}

/**
 * print_vrs - prints the version of the ELF header file.
 * @hdr: ELF header
 */
void print_vrs(char *hdr)
{
	printf("  %-35s%d", "Version:", hdr[6]);
	printf("%s", hdr[6] == EV_CURRENT ? " (current)\n" : "\n");
}

/**
 * print_osabi - prints the OS/ABI of the ELF header file.
 * @hdr: ELF header
 */
void print_osabi(char *hdr)
{
	char *os[18] = {"System V", "HP-UX", "NetBSD", "Linux", "GNU Hurd", "",
		"Solaris", "AIX", "IRIX", "FreeBSD", "Tru64", "Novell Modesto",
		"OpenBSD", "Open VMS", "NonStop Kernel", "AROS", "Fenix OS",
		"CloudABI"};

	printf("  %-35s", "OS/ABI:");
	if (hdr[7] >= 0 && hdr[7] <= 17)
		printf("UNIX - %s\n", os[(int)hdr[7] + 1]);
	else
		printf("<unknown: %02x>\n", hdr[7]);
}

/**
 * print_type - prints the filetype of the ELF header file.
 * @hdr: ELF header
 */
void print_type(char *hdr)
{
	int i = hdr[5] == 1 ? 16 : 17;
	char *type[4] = {"REL (Relocatable", "EXEC (Executable",
		"DYN (Shared object", "CORE (Core"};

	printf("  %-35s", "Type:");
	if (hdr[i] > 0 && hdr[i] < 5)
		printf("%s file)\n", type[(int)hdr[i] - 1]);
	else
		printf("<unknown>: %x\n", hdr[i]);
}

/**
 * print_entry - prints the entry point of the ELF header file.
 * @hdr: ELF header
 */
void print_entry(char *hdr)
{
	uint64_t addr;

	if (hdr[EI_CLASS] == ELFCLASS64)
		addr = (uintptr_t)(*(uint64_t *)(hdr + 0x18));

	else
		addr = (uintptr_t)(*(uint32_t *)(hdr + 0x18));
	printf("  %-35s0x%lx\n", "Entry point address:", addr);
}
/**
 * main - prints the information contained in the ELF header of a given file
 * @ac: number of arguments
 * @av: array of arguments
 *
 * Return: 0 on success,
 * or the corresponding error code (97, 98, 99, or 100) on failure.
 */
int main(int ac, char *av[])
{
	char *hdr;
	int op, re, i;

	if (ac != 2)
		exit(97);

	op = open(av[1], O_RDONLY);
	hdr = malloc(sizeof(Elf64_Ehdr));
	re = read(op, hdr, sizeof(Elf64_Ehdr));
	if (op == -1 || !hdr || re == -1)
	{
		close_fd(op);
		free(hdr);
		err(av[1], 98);
	}

	if (hdr[0] != 127 || hdr[1] != 'E' || hdr[2] != 'L' || hdr[3] != 'F')
		err("", 127);

	printf("ELF Header:\n  Magic:   ");
	for (i = 0; i < 16; i++)
		printf("%02x ", (unsigned int) hdr[i]);
	printf("\n");
	print_class(hdr);
	print_data(hdr);
	print_vrs(hdr);
	print_osabi(hdr);
	printf("  %-35s%d\n", "ABI Version:", hdr[8]);
	print_type(hdr);
	print_entry(hdr);

	return (0);
}
