#!/usr/bin/python3

import re
import json
import argparse

def parse_misra_checkers(input_file: str, output_file: str) -> None:
    """
    Parses a C++ source file to extract MISRA rule checkers and generates a JSON file.

    Args:
        input_file (str): The path to the input C++ file (e.g., MISRATidyModule.cpp).
        output_file (str): The path to the output JSON file.

    Returns:
        None
    """
    # Read the entire file content
    with open(input_file, 'r', encoding='utf-8') as file:
        content = file.read()

    # Split the content into statements using semicolon as a delimiter
    statements = content.split(';')

    # Regular expression pattern to match CheckFactories.registerCheck entries
    pattern = re.compile(
        r'CheckFactories\.registerCheck<(\w+)>\s*\(\s*"misra-c(?P<year>\d+)-'
        r'(?P<level>\w+)-(?P<id>[\d\.]+)"\s*\)'
    )

    # Mapping of level abbreviations to full descriptions
    level_mapping = {
        "adv": "Advisory",
        "req": "Required",
        "man": "Mandatory"
    }

    # Dictionary to store MISRA C 2012 and MISRA C 2023 rules
    misra_standards = {
        "2012": {"standard": "MISRA C 2012", "rules": []},
        "2023": {"standard": "MISRA C 2023", "rules": []}
    }

    # Iterate through each statement and apply regex to extract relevant information
    for statement in statements:
        match = pattern.search(statement)
        if match:
            implementation = match.group(1)
            year = match.group("year")
            level = level_mapping.get(match.group("level").lower(), match.group("level"))
            rule_id = match.group("id")

            if year in misra_standards:
                misra_standards[year]["rules"].append({
                    "type": "Rule",
                    "id": rule_id,
                    "level": level,
                    "classname": implementation
                })

    # Write the extracted data to a JSON file
    with open(output_file, 'w', encoding='utf-8') as json_file:
        json.dump(list(misra_standards.values()), json_file, indent=2)


if __name__ == "__main__":
    # Argument parser to handle input and output file paths
    parser = argparse.ArgumentParser(description="Extract MISRA rule checkers from a C++ source file.")
    parser.add_argument("-f", "--file", required=True, help="Input C++ file (e.g., MISRATidyModule.cpp)")
    parser.add_argument("-o", "--output", required=True, help="Output JSON file")
    args = parser.parse_args()

    # Run the parsing function with provided arguments
    parse_misra_checkers(args.file, args.output)
